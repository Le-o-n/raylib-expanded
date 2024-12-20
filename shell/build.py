import os
import glob


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

include_dirpaths: list[str] = [
    os.path.join(
        libraries_dirpath,
        "raylib-5.5_win64_mingw-w64",
        "include"
    )
]

library_dirpaths: list[str] = [
    os.path.join(
        libraries_dirpath,
        "raylib-5.5_win64_mingw-w64",
        "lib"
    )
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
