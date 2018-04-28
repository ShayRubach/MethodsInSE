
  
Methods In Software Engineering
==

**Contributers** <br/>
[Shay Rubach](https://github.com/ShayRubach) <br/>
[Idan Lazimi](https://github.com/idanlazimi)

## Useful links & tools
- [Microsoft Console API](https://docs.microsoft.com/en-us/windows/console/console-reference)
- [Automatic ASCII Generator](http://patorjk.com/software/taag/#p=display&h=0&f=Broadway&t=Ascii%20lover)
- [StackEdit.io - Edit README online](https://stackedit.io/app#)

### Tools
- Visual Studio Community Edition 2015
- Windows.h library (Win API)
<br/>_**Diclaimer:**_ <br/>all of the code was developed on and for a windows OS environment. <br/> Using this on a Linux/Mac/Other OS will require adapters such as [Wine](https://www.winehq.org/) etc and are currently not supported on our instructions.
## Workshop Lessons Breakdown:

**The Rippin You Off With a Smile Bank - Loans & Mortgages**  ![image](https://user-images.githubusercontent.com/21342315/39082573-c637364c-4555-11e8-8c27-24e43bc943ff.png) <br/>

1. Create a Table of Demands [for this Customer Story](http://online.shenkar.ac.il/pluginfile.php/288299/mod_assign/introattachment/0/%D7%A1%D7%99%D7%A4%D7%95%D7%A8%20%D7%9C%D7%A7%D7%95%D7%97%20%D7%9E%D7%A4%D7%95%D7%A8%D7%98.pdf?forcedownload=1)
2. Create matching UML Diagrams (Use Case, Deployment, Activity)
3. Develope two small applications: <br/>
	3.1. App #1 - Text Box <br/>
	3.2. App #2 - Check List <br/> 

### Table of Demands
See table [here](https://drive.google.com/file/d/1UrFaYvd2ghG_SokdfR7_1LvLp0484cvb/view?ts=5ad75337) or alternatively [here](https://www.scribd.com/document/377661202/Demand-Table)

### UML Diagrams
[Organization Level UC Diagram](https://www.scribd.com/document/377635445/MISE-Org-Lvl-Uc-Diag)
[Deployment Diagram](https://ibb.co/mi4bBx) 
[System Level UC Diagram](https://www.scribd.com/document/377635412/MISE-Sys-Lvl-Uc-Diag)
[Activity Diagram](https://ibb.co/kDaNjH) 
	
### App #1 - Text Box

Detailed instruction can be found [here](https://goo.gl/j8laap)

![text_box](https://user-images.githubusercontent.com/21342315/38980954-760b4cd2-43be-11e8-9e9c-48df3106a535.JPG) <br/><br/>

#### Note <br/>
Setting up the text box size, color and position on the screen can be done via main.cpp :</br>

```cpp
#define RGB (50|1|30)
#define TB_HEIGHT	(4)
#define TB_WIDTH	(25)
#define SCREEN_POS_X (30)
#define SCREEN_POS_Y (10)
```
To turn on debug output (to the local file 'debug.txt') just **comment out** this 
```cpp 
#define DEBUG_NONE
``` 
in 'text_box.h' </br>

#### Running via Visual Studio
* git clone https://github.com/ShayRubach/MethodsInSE.git
* Open your Visual Studio IDE
* Go to File->Open->Proejct/Solution.. (Ctrl+O) and choose the TextBox project
* Go to Project->Properties->Linker->System and change the SubSystem to 'Console (/SUBSYSTEM:CONSOLE)'
* Compile & Run (Ctrl+F5)

#### Running via Makefile
TODO

---

### App #2 - Check List

Detailed instruction can be found [here](https://goo.gl/j8laap)
#### How to use the app? <br/>
- Move with ↑ ↓ only to navigate between items
- Use Spacebar to check/uncheck an item from the list

![capture2](https://user-images.githubusercontent.com/21342315/39076730-7e3696ce-44fd-11e8-9ff0-d600a94fd08b.JPG)

#### Note <br/>
Like in the first task, setting up the check list dimensions, how many items will the list hold, color and position on the screen can be done via main.cpp :</br>

Notice the unique declaration in this project. The items count will be equal to the Y dimension at max.</br>
```cpp
#define ITEMS_COUNT (8)
```


#### Running via Visual Studio
* Follow instruction as in Task #1 but choose the CheckBox project

#### Running via Makefile
* Follow instruction as in Task #1