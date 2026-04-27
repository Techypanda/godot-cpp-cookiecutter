# {{ cookiecutter.project_name }}

## Description

{{ cookiecutter.project_description }}

## Project Structure

- .vscode
This is a folder containing bindings for vscode, it will make dev much easier
- game
This folder should contain your godot game "production" version
- playground
This folder you can treat as a your game "dev" version, throw quick tests in here as it wont go public ideally
- godot-cpp
This folder is the godot c++ bindings for writing C++
- godot
This folder contains the engine source code, useful for references aswell as directly building and using the engine, I suggest to use the engine in this folder rather then a locally installed one so you can have dev symbols

## Building

### Development

```
scons dev_build=yes debug_symbols=yes
```

### Production/Staging to players

Use build.ps1 as a template for this

## Useful Defines

(See SConstruct for how i hacked this together)
- `CLIENT` => is present in client builds
- `SERVER` => is present in server builds 