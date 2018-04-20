Methods In Software Engineering
==

**Contributers** <br/>
[Shay Rubach](https://github.com/ShayRubach) <br/>
[Idan Lazimi](https://github.com/idanlazimi)

## Useful links
- [Microsoft Console API](https://docs.microsoft.com/en-us/windows/console/console-reference)
- [Automatic ASCII Generator](http://patorjk.com/software/taag/#p=display&h=0&f=Broadway&t=Ascii%20lover)

## Workshop Lessons

---


### Lesson #1 - Text Box

Task Instruction can be found [here](https://goo.gl/j8laap)

![text_box](https://user-images.githubusercontent.com/21342315/38980954-760b4cd2-43be-11e8-9e9c-48df3106a535.JPG) <br/><br/>

#### Note <br/>
Setting the text box size, color and position on the screen can be done via main.cpp :</br>

`#define RGB (50|1|30)` </br>
`#define TB_HEIGHT	(4)` </br>
`#define TB_WIDTH	(25)` </br>
`#define SCREEN_POS_X (30)` </br>
`#define SCREEN_POS_Y (10)` </br>

To turn on debug output (to the local file 'debug.txt') just **comment out** this `#define DEBUG_NONE` in 'text_box.h' </br>

#### Running via Visual Studio
* git clone https://github.com/ShayRubach/MethodsInSE.git
* Open your Visual Studio IDE
* Go to File->Open->Proejct/Solution.. (Ctrl+O) and choose the TextBox project
* Go to Project->Properties->Linker->System and change the SubSystem to 'Console (/SUBSYSTEM:CONSOLE)'
* Compile & Run (Ctrl+F5)

#### Running via Makefile
TODO

---

### Lesson #2 - Check Box

Task Instruction can be found [here](https://goo.gl/j8laap)
#### How to use the app? <br/>
- Move with ↑ ↓ only to navigate between items
- Use Spacebar to check/uncheck an item from the list

![capture2](https://user-images.githubusercontent.com/21342315/39076730-7e3696ce-44fd-11e8-9ff0-d600a94fd08b.JPG)

#### Note <br/>
Like in the first task, setting the check list dimensions, how many items will the list hold, color and position on the screen can be done via main.cpp :</br>

Notice the unique declaration in this project. The items count will be equal to the Y dimension at max.</br>
`#define ITEMS_COUNT (8)`


#### Running via Visual Studio
* Follow instruction as in Task #1 but choose the CheckBox project

#### Running via Makefile
* Follow instruction as in Task #1