param (
    [Parameter(Mandatory=$true)]
    [string]$jsonConfigFilePath,

    [Parameter(Mandatory=$true)]
    [string]$dumpFolderPath,

    [Parameter(Mandatory=$true)]
    [string]$MaximumFolderNumber
)

$jsonConfig = Get-Content -Raw -Path $jsonConfigFilePath | ConvertFrom-Json

$hostname = $jsonConfig.server
$port = $jsonConfig.port
$username = $jsonConfig.username
$password = $jsonConfig.password
$databases = $jsonConfig.databases

$timestamp = Get-Date -Format "yyyy_MM_dd_HH_mm_ss"
$dumpFileNamePrefix = "database_dump"

$dumpFolder = New-Item -ItemType Directory -Path "$dumpFolderPath/$timestamp" -Force

$existingDumpFolders = Get-ChildItem -Path $dumpFolderPath -Directory | Sort-Object -Property Name

if ($existingDumpFolders.Count -gt $MaximumFolderNumber) {
    $foldersToDelete = $existingDumpFolders | Select-Object -First ($existingDumpFolders.Count - $MaximumFolderNumber)
    foreach ($folder in $foldersToDelete) {
        $folderPath = Join-Path -Path $dumpFolderPath -ChildPath $folder.Name
        Write-Host "Deleting folder: $folderPath"
        Remove-Item -Path $folderPath -Recurse -Force
    }
}

foreach ($database in $databases) {
    $dumpFileName = "${dumpFileNamePrefix}_${database}.sql"
    $dumpFilePath = Join-Path -Path $dumpFolder.FullName -ChildPath $dumpFileName

    $mysqldumpCommand = "mysqldump.exe"
    $mysqldumpArgs = "--host=$hostname", "--port=$port", "--user=$username", "--password=$password", "--result-file=$dumpFilePath", $database

    Write-Host "Creating database dump for $database..."
    Start-Process -FilePath $mysqldumpCommand -ArgumentList $mysqldumpArgs -Wait

    Write-Host "Database dump for $database created at: $dumpFilePath"
}