1. Make so that the .pdf of documentation from LaTeX is generated.
2. Make so that the html version of documentation is generated via GitHub action and uploaded to given environment.
3. Fix the error show when {Module name}_docs exec is run.
4. cc1plus.exe: warning: .../PokerOnline/common/conf/config.h: not a directory -<<< fix this (make the generated sources be in Build folder)
	* fixed so that the config is generated in correct spot, but inside a lib we cannot include it :(