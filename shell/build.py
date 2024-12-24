import os
import glob
import platform
import sys
from resolve_library import Raylib

FILE_DIRPATH: str = os.path.abspath(os.path.dirname(__file__))
ROOT: str = os.path.join(
    FILE_DIRPATH,
    os.pardir
)


# ===============================================================
# ===============================================================
# ============= Global Settings for Compilation =================
# ===============================================================
# ===============================================================

COMPILER: str = "gcc"
OUT: list[str] = [
    ROOT, "build", "main.exe"
]
C_FILES: list[list[str]] = [
    [ROOT, "src", "*.c"]
]

INCLUDE_PATHS: list[list[str]] = [
    [ROOT, "include"],
    [ROOT, "libraries", "clay-0.12", "include"],
    [ROOT, "libraries", "raylib-5.5", Raylib.get_dist(), "include"],
]

LIBRARY_PATHS: list[list[str]] = [
    [ROOT, "libraries", "raylib-5.5", Raylib.get_dist(), "lib"]
]

LIBRARIES: list[str] = [
    "raylib",
    "opengl32",
    "gdi32",
    "winmm"
]

# ===============================================================
# ===============================================================
# ===============================================================
# ===============================================================
# ===============================================================


def get_build_command(
    compiler: str,
    out: str,
    c_filepaths: list[str],
    include_dirpaths: list[str],
    library_dirpaths: list[str],
    libraries: list[str]
) -> str:
    
    out_str: str = f"-o \"{out}\""
    
    c_filepaths_str: str = " ".join(
        f"\"{c_filepath}\""
        for c_filepath
        in c_filepaths
    )
    
    include_dirpaths_str: str = " ".join([
        f"-I\"{include_dirpath}\""
        for include_dirpath
        in include_dirpaths
    ])
    
    library_dirpaths_str: str = " ".join([
        f"-L\"{library_dirpath}\""
        for library_dirpath 
        in library_dirpaths
    ])
    
    libraries_str: str = " ".join([
        f"-l{library}"
        for library
        in libraries
    ])
    
    build_command: list[str] = [
        compiler,
        out_str,
        c_filepaths_str,
        include_dirpaths_str,
        library_dirpaths_str,
        libraries_str
    ]
    
    return build_command
    
def main() -> None:
    
    if len(C_FILES) == 0:
        print("No C files found in the src directory.")
        exit(1)
     
    out_fullpath: str = os.path.join(*OUT)
    
    c_file_fullpaths: list[str] = []
    
    c_file: list[str]
    for c_file in C_FILES:
        
        c_file_glob: str = os.path.join(*c_file)
    
        c_file_paths: list[str] = glob.glob(
            c_file_glob
        )  

        for path in c_file_paths:
            c_file_fullpaths.append(path)
    
    include_fullpaths: list[str] = [
        os.path.join(*include)
        for include
        in INCLUDE_PATHS
    ]
    
    library_fullpaths: list[str] = [
        os.path.join(*library_path)
        for library_path
        in LIBRARY_PATHS
    ]  
    
    command: str = " ".join(
        get_build_command(
            COMPILER,
            out_fullpath,
            c_file_fullpaths,
            include_fullpaths,
            library_fullpaths,
            LIBRARIES
            
        )
    )
    pass
    # gcc -o build/test.exe test.c -I"C:\raylib\include" -L"C:\raylib\lib" -lraylib -lopengl32 -lgdi32 -lwinmm

    print(f"Running command: {command}\n")
    os.system(command)
    



if __name__ == "__main__":
    main()
    