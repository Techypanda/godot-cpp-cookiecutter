param (
    [Parameter()][switch]$Release
)

Write-Host "Is release build: $release"
$ExportType = "--export-debug"
if ($Release) {
    $ExportType = "--export-release"
}

rm -Force playground/bin/*.dll -Recurse -ErrorAction Ignore
rm -Force playground/bin/*.exp -Recurse -ErrorAction Ignore
rm -Force playground/bin/*.ilk -Recurse -ErrorAction Ignore
rm -Force playground/bin/*.pdb -Recurse -ErrorAction Ignore
rm -Force playground/bin/*.TMP -Recurse -ErrorAction Ignore
rm -Force playground/bin/*.lib -Recurse -ErrorAction Ignore

if ($Release) {
    Write-Host "Compiling C++ in release..."
    scons dev_build=no target=template_release
} else {
    Write-Host "Compiling C++ in dev build..."
    scons dev_build=yes debug_symbols=yes
}

Write-Host "Cooking Client..."

rm -Force builds/client -Recurse -ErrorAction Ignore
mkdir builds/client

Start-Process "C:\Program Files\Godot\Godot_v4.6.2-stable_win64.exe" -ArgumentList "--headless","--path","playground",$ExportType,"`"Windows Desktop`"","C:\Users\User\Documents\GodotGames\brewing\builds\client\client.exe" -Wait -ErrorAction Ignore
Write-Host "Done"