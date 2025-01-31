import os
import glob
import platform
import sys
import argparse
import shutil
import json


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

WORKING_DIR_INCLUDE_PATH: list[str] = [ROOT, "include"]

INCLUDE_PATHS: list[list[str]] = [
    WORKING_DIR_INCLUDE_PATH,
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


def generate_asset_paths(
    asset_dirpath: str
) -> None:

    mp3_file_paths: list[str] = glob.glob(
        os.path.join(os.path.basename(asset_dirpath), "**", "*.mp3"),
        recursive=True,
        root_dir=os.path.join(asset_dirpath, os.pardir)
    )

    mp3_file_var_names: list[str] = []

    path: str
    for path in mp3_file_paths:
        path_formatted: str = os.path.splitext(path)[0]
        path_formatted = path_formatted.upper()
        path_formatted = path_formatted.replace(os.path.sep, "_")
        path_formatted = f"{path_formatted}"
        mp3_file_var_names.append(path_formatted)

    write_buffer: list[str] = []

    write_buffer.append("#ifndef ASSETS_H")
    write_buffer.append("#define ASSETS_H\n")

    var_name: str
    path: str
    for var_name, path in zip(mp3_file_var_names, mp3_file_paths):
        escaped_path: str = json.dumps(path)

        write_buffer.append(f"#define {var_name} {escaped_path}")

    write_buffer.append("\nstatic const char* ASSETS_AUDIO_PATHS[] = {")

    var_name: str
    for i, var_name in enumerate(mp3_file_var_names):
        comma: str = "," if i < len(mp3_file_var_names) - 1 else ""
        write_buffer.append(f"    {var_name}{comma}")
    write_buffer.append("};\n")

    write_buffer.append(f"# define ASSETS_AUDIO_PATHS_COUNT {len(mp3_file_var_names)}\n")

    write_buffer.append("# endif")

    with open(os.path.join(*WORKING_DIR_INCLUDE_PATH, "assets.h"), "w") as f:

        f.write("\n".join(write_buffer))


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


def build_c(debug: bool, no_opt: bool, verbose: bool):

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
            debug,
            no_opt
        )
    )

    # gcc -o build/test.exe test.c -I"C:\raylib\include" -L"C:\raylib\lib" -lraylib -lopengl32 -lgdi32 -lwinmm

    if verbose:
        print(f"Running command: {command}\n")

    os.system(command)

    shutil.copytree(
        ASSET_DIRPATH,
        BUILD_ASSETS_DIRPATH,
        dirs_exist_ok=True
    )


def main() -> None:

    if len(C_FILES) == 0:
        print("No C files found in the src directory.")
        exit(1)

    # Create an ArgumentParser object
    parser = argparse.ArgumentParser(
        description="Build script for the project."
    )

    parser.add_argument(
        "--all",
        action="store_true",
        help="Make all"
    )

    parser.add_argument(
        "--c",
        action="store_true",
        help="Make c files"
    )

    parser.add_argument(
        "--assets",
        action="store_true",
        help="Make asset paths header"
    )

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

    if args.all or args.assets:
        generate_asset_paths(ASSET_DIRPATH)

    if args.all or args.c:
        build_c(args.debug, args.no_opt, args.verbose)


if __name__ == "__main__":
    main()
