import os
import glob
import platform
import sys


def get_raylib_distname() -> str:
    
    system: str = platform.system().lower()
    architecture: str = platform.architecture()[0]
    bits: str = "32" if architecture == "32bit" else "64"

    folder: str
    if system == "linux":
        folder = f"raylib-5.5_linux{'i386' if bits == '32' else '_amd64'}"
        
    elif system == "windows":
        compiler = "mingw-w64"
        folder = f"raylib-5.5_win{bits}_{compiler}"
    
    else:
        raise Exception("Unsupported OS")

    return folder
    

BUILD_FILENAME: str = "main.exe"


file_dirpath: str = os.path.abspath(
    os.path.dirname(__file__)
)

root_dirpath: str = os.path.join(
    file_dirpath,
    os.pardir
)

src_dirpath: str = os.path.join(
    root_dirpath,
    "src"
)

build_dirpath: str = os.path.join(
    root_dirpath,
    "build"
)
os.makedirs(
    build_dirpath,
    exist_ok=True
)

libraries_dirpath: str = os.path.join(
    root_dirpath,
    "libraries"
)

raylib_dist_dirpath: str = os.path.join(
    libraries_dirpath,
    "raylib-5.5",
    get_raylib_distname()
)

raylib_include_dirpath: str = os.path.join(
    raylib_dist_dirpath,
    "include"
)

raylib_lib_dirpath: str = os.path.join(
    raylib_dist_dirpath,
    "lib"
)

local_include_dirpath: str = os.path.join(
    root_dirpath,
    "include"
)

include_dirpaths: list[str] = [
    local_include_dirpath,
    raylib_include_dirpath
]

library_dirpaths: list[str] = [
    raylib_lib_dirpath
]

libraries: list[str] = [
    "raylib",
    "opengl32",
    "gdi32",
    "winmm"
]


c_filepaths: list[str] = glob.glob(
    os.path.join(
        src_dirpath,
        "*.c"
    )
)
output_build_filepath: str = os.path.join(
    build_dirpath,
    BUILD_FILENAME
)
compiler_string: str = "gcc"
output_string: str = f"-o {output_build_filepath}"
c_files_string: str = ' '.join(c_filepaths)
include_dirpaths_string: str = " ".join([
    f"-I\"{include_dirpath}\""
    for include_dirpath in
    include_dirpaths
])
library_dirpaths_string: str = " ".join([
    f"-L\"{library_dirpath}\""
    for library_dirpath in
    library_dirpaths
])
libraries_string: str = " ".join([
    f"-l{lib}"
    for lib in libraries
])

if __name__ == "__main__":
    if c_filepaths:

        command: str = " ".join([
            compiler_string,
            output_string,
            c_files_string,
            include_dirpaths_string,
            library_dirpaths_string,
            libraries_string
        ])

        # gcc -o build/test.exe test.c -I"C:\raylib\include" -L"C:\raylib\lib" -lraylib -lopengl32 -lgdi32 -lwinmm

        print(f"Running command: {command}")
        os.system(command)
    else:
        print("No C files found in the src directory.")
