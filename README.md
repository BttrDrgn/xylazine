# Xylazine
Xylazine is a reimplementation project for Need for Speed: Underground 2 which aims to logically match, not bytecode match, the inner workings of the Speed engine, EA Graphics Library, Realcore, and most importantly, the game's logic.
### The Name
Xylazine is drug, do your own research as to what this drug is, and the rest of the Speed engine is built off a bunch of other subsystems that are named after street drugs. For example, Acid, Codeine, Ectasy, and the main engine "Speed" is in reference to amphetamines. This is not a crash course on drugs and we very much do not condone any use of drugs, the name Xylazine just sounds cool and goes with the flow that Blackbox used for their naming schemes.


## Progress
In the current state of the project, progress cannot be fully realized by garunteed data. The current estimate is 15,000 functions as recognized by IDA Pro's subroutine checks.  
Progress can be checked by running the `progcalc.bat` in the root of the directory.

## Compiling

### Prerequisites
To compile Xylazine, you will need:
- [Visual Studio 2022](https://visualstudio.microsoft.com/vs/)
     - Install C++ modules when prompted (v143 build tools)
- [DirectX 9 June 2010 SDK](https://www.microsoft.com/en-US/download/details.aspx?id=6812)

### Instructions
- Run `generate.bat` at the root of the project folder
- A `build` folder will be generated with the `xylazine.sln` file
- Run `xylazine.sln` in Visual Studio 2022 to open the project
- Compile


## Installing
Xylazine is not yet ready for public use. While it does technically run the game almost identically to the retail PC release, there is no point in a release binary. However, if you still wish to use Xylazine, you can find pre-built debug binaries in the [build actions](https://github.com/BttrDrgn/xylazine/actions/workflows/build.yml) section of the repository.
