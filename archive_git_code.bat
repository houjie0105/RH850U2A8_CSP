@REM Package current code

@git > nul | @goto no_git
@for /F %%i in ('git rev-parse --short HEAD') do @( @set commitid=%%i)
@for /F %%i in ('git rev-parse --abbrev-ref HEAD') do @( @set branch=%%i)
@set dirname=%branch%_%commitid%_%date:~0,4%%date:~5,2%%date:~8,2%%time:~0,2%%time:~3,2%%time:~6,2%
@set "dirname=%dirname: =0%"
@git archive -o ../%dirname%.zip HEAD

@7z > nul | @goto no_7z
@cd ..
@7z x ./%dirname%.zip -o%dirname% > nul
@del %dirname%.zip
@7z a -t7z -r -mx9 -mmt4 -prenesas -sdel %dirname%.7z ./%dirname% > nul
@goto :eof

:no_git
@echo Not install git!!
@pause
exit

:no_7z
@echo Not install 7z!!
@pause
exit
