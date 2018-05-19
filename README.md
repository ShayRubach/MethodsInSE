


  
Methods In Software Engineering
==

**Contributers** <br/>
[Shay Rubach](https://github.com/ShayRubach) <br/>
[Idan Lazimi](https://github.com/idanlazimi) <br/>
[Alon Golan](https://github.com/alongolan1991)

## Useful links & tools
- [Microsoft Console API](https://docs.microsoft.com/en-us/windows/console/console-reference)
- [Automatic ASCII Generator](http://patorjk.com/software/taag/#p=display&h=0&f=Broadway&t=Ascii%20lover)
- [StackEdit.io - Edit README online](https://stackedit.io/app#)
- [UML Notation Summery](http://umich.edu/~eecs381/handouts/UMLNotationSummary.pdf)

### Tools
- Visual Studio Community Edition 2015
- Windows.h library (Win API)
<br/>_**Disclaimer:**_ <br/>all of the code was developed on and for a windows OS environment. <br/> Using this on a Linux/Mac/Other OS will require adapters such as [Wine](https://www.winehq.org/) etc and are currently not supported on our instructions.
## Workshop Lessons Breakdown:

**The Rippin You Off With a Smile Bank - Loans & Mortgages**  ![image](https://user-images.githubusercontent.com/21342315/39082573-c637364c-4555-11e8-8c27-24e43bc943ff.png) <br/>

The final project of this course is to develop an API (in our case, a [C++ Static Library]()) which will be provided to the Bank's developers & employees in order to be able to dynamically create Psuedo Graphical forms for their organization's system. This project will be broken down to ***sub tasks*** and embrace the [Agile Methodology](https://en.wikipedia.org/wiki/Agile_software_development), commonly used in software development.<br>***Sub tasks***: 
1. Create a Table of Demands [for this Customer Story](http://online.shenkar.ac.il/pluginfile.php/288299/mod_assign/introattachment/0/%D7%A1%D7%99%D7%A4%D7%95%D7%A8%20%D7%9C%D7%A7%D7%95%D7%97%20%D7%9E%D7%A4%D7%95%D7%A8%D7%98.pdf?forcedownload=1)
2. Create matching UML Diagrams (Use Case, Deployment, Activity)
3. Develope two small applications: <br/>
	3.1. App #1 - Text Box <br/>
	3.2. App #2 - Check List <br/> 

4. Create a detailed Class Diagram following [this document](https://www.scribd.com/document/378911321/%D7%9E%D7%A4%D7%A8%D7%98-%D7%A4%D7%A7%D7%93%D7%99%D7%9D)  using 2-3 [Design Patterns](https://sourcemaking.com/design_patterns) ![fire](https://user-images.githubusercontent.com/21342315/39946683-684328a0-556f-11e8-92ee-7a42759d3933.png) [NEW!] ![fire](https://user-images.githubusercontent.com/21342315/39946683-684328a0-556f-11e8-92ee-7a42759d3933.png)
5. Prepare a work plan for the project, from start to finish. Use [Gantt Charts](http://www.gantt.com/) to design your work plan. You can use [MSProject](https://products.office.com/en/project/project-and-portfolio-management-software?tab=tabs-1) or any other project management software for your team (we used free one called [GanttProject](https://www.ganttproject.biz/) ).<br>Detailed instruction can be found [here](http://online.shenkar.ac.il/mod/assign/view.php?id=107138)
6. Develop a example of a program using your own awsome API, demonstrating all of the behavior you were required to achieve on the early [Customer Story Form](http://online.shenkar.ac.il/pluginfile.php/288299/mod_assign/introattachment/0/%D7%A1%D7%99%D7%A4%D7%95%D7%A8%20%D7%9C%D7%A7%D7%95%D7%97%20%D7%9E%D7%A4%D7%95%D7%A8%D7%98.pdf?forcedownload=1).
### Table of Demands
See table [here](https://drive.google.com/file/d/1UrFaYvd2ghG_SokdfR7_1LvLp0484cvb/view?ts=5ad75337) or alternatively [here](https://www.scribd.com/document/377661202/Demand-Table)
### UML Diagrams
[Organization Level UC Diagram](https://www.scribd.com/document/377635445/MISE-Org-Lvl-Uc-Diag) <br/>[Deployment Diagram](https://ibb.co/mi4bBx) <br/>
[System Level UC Diagram](https://www.scribd.com/document/377635412/MISE-Sys-Lvl-Uc-Diag) <br/>[Activity Diagram](https://ibb.co/kDaNjH) <br/>
[Class Diagram including Design Patterns](https://www.scribd.com/document/379009877/MISE-Class-Diagram-With-Dp) ![fire](https://user-images.githubusercontent.com/21342315/39946683-684328a0-556f-11e8-92ee-7a42759d3933.png) [NEW!] ![fire](https://user-images.githubusercontent.com/21342315/39946683-684328a0-556f-11e8-92ee-7a42759d3933.png)
	
### App #1 - Text Box
Detailed instruction can be found [here](https://www.youtube.com/watch?v=d5IrqkTYfL4)
![text_box](https://user-images.githubusercontent.com/21342315/38980954-760b4cd2-43be-11e8-9e9c-48df3106a535.JPG) <br/><br/>
#### Note <br/>
Setting up the text box size, color and position on the screen can be done via main.cpp :</br>
```cpp#define RGB (50|1|30)
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
* git clone https://github.com/ShayRubach/MethodsInSE.git* Open your Visual Studio IDE
* Go to File->Open->Proejct/Solution.. (Ctrl+O) and choose the TextBox project* Go to Project->Properties->Linker->System and change the SubSystem to 'Console (/SUBSYSTEM:CONSOLE)'
* Compile & Run (Ctrl+F5)
#### Running via Makefile
TODO
---
### App #2 - Check List
Detailed instruction can be found [here](https://www.youtube.com/watch?v=d5IrqkTYfL4)
#### How to use the app? <br/>
- Move with ↑ ↓ only to navigate between items- Use Spacebar to check/uncheck an item from the list

![capture2](https://user-images.githubusercontent.com/21342315/39076730-7e3696ce-44fd-11e8-9ff0-d600a94fd08b.JPG)
#### Note <br/>
Like in the first task, setting up the check list dimensions, how many items will the list hold, color and position on the screen can be done via main.cpp :</br>
Notice the unique declaration in this project. The items count will be equal to the Y dimension at max.</br>
```cpp#define ITEMS_COUNT (8)
```

#### Running via Visual Studio
* Follow instruction as in Task #1 but choose the CheckBox project
#### Running via Makefile
* Follow instruction as in Task #1
### Project Workplan - Gantt Chart
This is a screenshot of our Pseudo Graphic Static Library API Project described with a Gantt Chart.<br> ***A short exaplanation on our work plan:*** 
- The projects consists of 5 main working cycles: Design & Architecture,  Development, QA, Debugging & Fixing bugs, Presentation of the final producat (a.k.a 'Delivery').- We diveded each and every workign cycle to as many independent sub tasks as we could while preserving the development logic and hierarchy in plan.
- We assigned an owner (or owners) to each and every cycle and each and every sub-task.- We assigned a reviewer and a review time for each and every one of the tasks.
- We prepared a safe-guard 'placeholder' on every cycle to keep our [Agile Effort Estimation](https://info.thoughtworks.com/rs/thoughtworks2/images/twebook-perspectives-estimation_1.pdf) plan as precise as possible.- Every task is colored and every single member is holding a unique color in the project so it would be easy to track its own work. Multiple asignees are indicated with a solid black color. 
Shay Rubach = Pink ![image](https://78.media.tumblr.com/88165ae8ac92635127d1e8d106e9bf0c/tumblr_inline_mgtqa6QGFJ1qk1or3.gif)<br> Idan Lazimi = Blue ![image](https://78.media.tumblr.com/b4eeded2a33828200b8c43b254a58122/tumblr_inline_mgtqahOFYp1qk1or3.gif)<br> Alon Golan = Yellow ![ star](https://www.practicesuite.com/wp-content/uploads/2017/06/star.png)<br> Multiple members = Black ![image](https://78.media.tumblr.com/tumblr_m5jqzgH4c41qb1380.gif) <br> The project can be downloaded [here](https://ufile.io/c4qf5) . You'll need to download the free software [GanttProject](https://www.ganttproject.biz/) to open the project.

![gantt_chart](https://user-images.githubusercontent.com/21342315/40268077-6c3ad64e-5b67-11e8-90b0-2ba410081e34.png)