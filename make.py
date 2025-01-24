import os
import glob
import platform
import sys
import argparse
import shutil

FILE_DIRPATH: str = os.path.abspath(
    os.path.dirname(__file__)
)
ROOT: str = os.path.join(
    FILE_DIRPATH
)
ASSET_DIRPATH: str = os.path.join(
    ROOT,
    "assets"
)
BUILD_DIRPATH: str = os.path.join(
    ROOT,
    "build"
)
os.makedirs(BUILD_DIRPATH, exist_ok=True)

BUILD_ASSETS_DIRPATH: str = os.path.join(
    BUILD_DIRPATH,
    os.path.basename(ASSET_DIRPATH)
)

# ===============================================================
# ===============================================================
# ============= Global Settings for Compilation =================
# ===============================================================
# ===============================================================

COMPILER: str = "gcc"
OUT: list[str] = [
    BUILD_DIRPATH, "main.exe"
]
C_FILES: list[list[str]] = [
    [ROOT, "src", "**/*.c"]
]

INCLUDE_PATHS: list[list[str]] = [
    [ROOT, "include"],
    [ROOT, "libraries", "clay-0.12", "include"],
    [ROOT, "libraries", "raylib-5.5", "raylib-5.5_win64_mingw-w64", "include"],
]

LIBRARY_PATHS: list[list[str]] = [
    [ROOT, "libraries", "raylib-5.5", "raylib-5.5_win64_mingw-w64", "lib"]
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
    libraries: list[str],
    debug: bool = False,
    no_optimisations: bool = False
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

    debug_str: str = ""

    if debug:
        debug_str = "-g"

    optimisation_str: str = ""

    if no_optimisations:
        optimisation_str = "-O0"

    build_command: list[str] = [
        compiler,
        out_str,
        c_filepaths_str,
        include_dirpaths_str,
        library_dirpaths_str,
        libraries_str,
        debug_str,
        optimisation_str
    ]

    return build_command


def main() -> None:

    if len(C_FILES) == 0:
        print("No C files found in the src directory.")
        exit(1)

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(
        description="Build script for the project."
    )

    # Add the --debug flag
    parser.add_argument(
        '--debug',
        action='store_true',
        help="Enable debug mode"
    )

    parser.add_argument(
        '--verbose',
        action='store_true',
        help="Enable verbose mode"
    )

    parser.add_argument(
        '--no-opt',
        action='store_true',
        help="Removes all compiler optimisations."
    )

    # Parse the command-line arguments
    args: argparse.Namespace = parser.parse_args()

    out_fullpath: str = os.path.join(*OUT)

    c_file_fullpaths: list[str] = []

    c_file: list[str]
    for c_file in C_FILES:

        c_file_glob: str = os.path.join(*c_file)

        c_file_paths: list[str] = glob.glob(
            c_file_glob,
            recursive=True
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
            LIBRARIES,
            args.debug,
            args.no_opt
        )
    )

    # gcc -o build/test.exe test.c -I"C:\raylib\include" -L"C:\raylib\lib" -lraylib -lopengl32 -lgdi32 -lwinmm

    if args.verbose:
        print(f"Running command: {command}\n")

    os.system(command)

    shutil.copytree(
        ASSET_DIRPATH,
        BUILD_ASSETS_DIRPATH,
        dirs_exist_ok=True
    )


if __name__ == "__main__":
    main()
