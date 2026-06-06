$rootDir = "app"

$folders = @(
    "$rootDir/src",
    "$rootDir/src/models",
    "$rootDir/src/services",
    "$rootDir/src/utils",
    "$rootDir/data",
    "$rootDir/tests",
    "$rootDir/docs"
)

foreach ($folder in $folders) {
    New-Item -ItemType Directory -Path $folder -Force | Out-Null
    Write-Host "Created folder: $folder"
}

Write-Host "`nProject skeleton created in '$rootDir'. Place source files under $rootDir/src, data files under $rootDir/data, and tests under $rootDir/tests."
