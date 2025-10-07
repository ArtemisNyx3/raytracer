cmake -B build
cmake --build build --config Debug
& .\build\Debug\raytracer.exe | Set-Content -Path image.ppm -Encoding String