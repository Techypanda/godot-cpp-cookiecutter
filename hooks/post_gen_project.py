import subprocess
import platform

def run_shell_stuff():
    print("setting up git submodules...")
    subprocess.call(
        ["git", "init"],
        shell=True
    )
    # godot-cpp (godot cpp bindings)
    subprocess.call(
        ["git", "submodule", "add", "https://github.com/godotengine/godot-cpp"],
        shell=True
    )
    # godot-engine (godot)
    subprocess.call(
        ["git", "submodule", "add", "https://github.com/godotengine/godot"],
        shell=True
    )
    # compile project
    subprocess.call(
        ["scons", "dev_build=yes", "debug_symbols=yes"],
        shell=True
    )
    # compile godot
    subprocess.call(
        ["scons", "dev_build=yes", "debug_symbols=yes"],
        cwd="godot",
        shell=True
    )
    # commit
    subprocess.call(
        ["git", "add", "*"],
        shell=True
    )
    subprocess.call(
        ["git", "commit", "-m", "\"bootstrap: cookie cutted\""],
        shell=True
    )

match platform.system().upper():
    case _:
        run_shell_stuff()