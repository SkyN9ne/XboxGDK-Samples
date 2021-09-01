@echo off

REM Build W/O Installing (BWOI) Example for the Microsoft GDK 
REM
REM This command sets a few specific variables to drive the build

if %1.==vspreview. goto :define_vs2019_preview
if %1.==vs2017. goto :define_vs2017_install_dir
if %1.==vs2019. goto :define_vs2019_install_dir
echo "Usage: setenv {vs2017 | vs2019 | vspreview} [GDK edition] [extracted GDK path]"
goto :eof

REM ****************************************************************************************************
REM VSInstallDir for Visual Studio 2019
REM ****************************************************************************************************
:define_vs2019_preview
if NOT EXIST "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Preview\" goto :define_vs2019_install_dir
ECHO *** Using VS 2019 Preview ***
SET VSInstallDir=%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Preview\
goto :vs_install_dir_defined

:define_vs2019_install_dir
if DEFINED VSInstallDir (goto :vs_install_dir_defined)
if NOT EXIST "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Enterprise\" goto :vs2019_install_dir_professional
ECHO *** Using VS 2019 Enterprise ***
SET VSInstallDir=%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Enterprise\
goto :vs_install_dir_defined

:vs2019_install_dir_professional
if NOT EXIST "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Professional\" goto :vs2019_install_dir_buildtools
ECHO *** Using VS 2019 Professional ***
SET VSInstallDir=%ProgramFiles(x86)%\Microsoft Visual Studio\2019\Professional\
goto :vs_install_dir_defined

:vs2019_install_dir_buildtools
if NOT EXIST "%ProgramFiles(x86)%\Microsoft Visual Studio\2019\BuildTools\" goto :vs2019_install_dir_unknown
ECHO *** Using VS 2019 Build Tools ***
SET VSInstallDir=%ProgramFiles(x86)%\Microsoft Visual Studio\2019\BuildTools\
goto :vs_install_dir_defined

:vs2019_install_dir_unknown
@echo Couldn't figure out your Visual 2019 installation directory (need to use Visual Studio 2019 Enterprise, Professional, or Build Tools)
goto :eof

REM ****************************************************************************************************
REM VSInstallDir for Visual Studio 2017
REM ****************************************************************************************************
:define_vs2017_install_dir
if DEFINED VSInstallDir (goto :vs_install_dir_defined)
if NOT EXIST "%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Enterprise\" goto :vs2017_install_dir_professional
SET VSInstallDir=%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Enterprise\
goto :vs_install_dir_defined

:vs2017_install_dir_professional
if NOT EXIST "%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Professional\" goto :vs2017_install_dir_buildtools
SET VSInstallDir=%ProgramFiles(x86)%\Microsoft Visual Studio\2017\Professional\
goto :vs_install_dir_defined

:vs2017_install_dir_buildtools
if NOT EXIST "%ProgramFiles(x86)%\Microsoft Visual Studio\2017\BuildTools\" goto :vs2017_install_dir_unknown
SET VSInstallDir=%ProgramFiles(x86)%\Microsoft Visual Studio\2017\BuildTools\
goto :vs_install_dir_defined

:vs2017_install_dir_unknown
@echo Couldn't figure out your Visual 2017 installation directory (need to use Visual Studio 2017 Enterprise, Professional, or Build Tools)
goto :eof
:vs_install_dir_defined

if EXIST "%VSInstallDir%MSBuild\Current\Bin\MSBuild.exe" (set "PATH=%VSInstallDir%MSBuild\Current\Bin;%PATH%")
if EXIST "%VSInstallDir%MSBuild\15.0\Bin\MSBuild.exe" (set "PATH=%VSInstallDir%MSBuild\15.0\Bin;%PATH%")

REM ****************************************************************************************************
REM Pick a folder for the extracted content (do not use a deep path or you will hit _MAX_PATH issues)
REM ****************************************************************************************************
if NOT %3.==. (set ExtractedFolder=%3) else (set ExtractedFolder=%~d0\xtrctd.sdks\BWOIExample)

REM ****************************************************************************************************
REM Figure out our target edition
REM ****************************************************************************************************
if NOT %2.==. (set XdkEditionTarget=%2) else (set XdkEditionTarget=210600)

echo ExtractedFolder=%ExtractedFolder%
echo XdkEditionTarget=%XdkEditionTarget%