# Godot CPP Cookie Cutter

This project allows you to quickly spinup a godot cpp repository following some sane practices to allow you to quickly get up and running with a godot cpp GDExtension.

## Where Are Best Practices Followed From?

https://github.com/godotengine/godot-cpp-template/tree/main is the official template from godot, this is just a cookie cutter more opinionated one i wrote


this repo is not better in any way just another approach

## Divergences from godot-cpp

DocGen, not sure everyone needs this so not including by default. I can figure out how to get that working but just resulting in alot of warnings by default i felt most users just don't care about

## Current Issues

1. Windows is only officially supported so far, linux/mac will fail the .vscode folder as its targeting windows
2. SConstruct is very hacky

## Prereq

[You will need to install cookiecutter for this to work, while scons was investigated i feel its more painful to get this to work](https://cookiecutter.readthedocs.io/en/stable/installation.html)

## Usage

```sh
1. vim cookiecutter.json
   => change values to what you want

2. cookiecutter .
```