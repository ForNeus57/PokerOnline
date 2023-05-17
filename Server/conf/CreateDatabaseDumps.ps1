$hostname = "localhost"         # MySQL server hostname
$port = 3306                    # MySQL server port
$username = "root"              # MySQL username
$password = "7755"              # MySQL password

$databases = @("dev", "prod")   # MySQL database name

$timestamp = Get-Date -Format "yyyy_MM_dd_HH_mm_ss"
$dumpFolderPath = "Server/docs/DatabaseDumps"
$dumpFileNamePrefix = "database_dump_$timestamp"

New-Item -ItemType Directory -Path "$dumpFolderPath/$timestamp"

foreach ($database in $databases) {
    $dumpFileName = "$timestamp/$dumpFileNamePrefix`_$database.sql"
    $dumpFilePath = Join-Path -Path $dumpFolderPath -ChildPath $dumpFileName

    $mysqldumpCommand = "mysqldump.exe"
    $mysqldumpArgs = "--host=$hostname", "--port=$port", "--user=$username", "--password=$password", "--result-file=$dumpFilePath", $database

    Write-Host "Creating database dump for $database..."
    Start-Process -FilePath $mysqldumpCommand -ArgumentList $mysqldumpArgs -Wait

    Write-Host "Database dump for $database created at: $dumpFilePath"
}