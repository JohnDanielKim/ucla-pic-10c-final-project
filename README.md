# ucla-pic-10c-final-project

The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970.[1] It is a zero-player game, meaning that its evolution is determined by its initial state, requiring no further input. One interacts with the Game of Life by creating an initial configuration and observing how it evolves. It is Turing complete and can simulate a universal constructor or any other Turing machine. (source: https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)

===========================================================================

I came up with the idea for my project browsing on Wikipedia; I chose the game of life because I thought it would be interesting to simulate the grid and didn't think it would be too insurmountable of a challenge, especially given the simple set of rules for the game. I did a lot of research before and during my completion of the project mainly on signal-slot connections, the different kinds of layouts, and the mouse/painting classes; the majority of my research was on the Qt documentation website and from the course discussion session notes and code, but I also ended up using Stack Overflow for many simpler questions during my coding.

Main struggles:
1. Sending numeric values through connect between windows/widgets
  - Due to my inexperience with Qt, I could not figure out how to send the integers I wanted to from the main window to the game window. I knew I had to use QObject::connect or some overloaded version of that, but I could not figure out how to adapt each side of the connect statement to pass by reference or by value; I eventually worked through this just by gaining experience with the connect statements while I was rewriting the other HW assignments and while I was looking through the Qt documentation. I also realized that the gamescreen did not need to have separate values for rows and columns, being that a square widget would work well enough for the purposes of the game
2. Constructing an efficent and workable gridscreen for actual gameplay
    - I did not know the most efficient way to make the grid of rectangles for gameplay. My ideas went as follows:
        - grid layout of push buttons that signal each other and change colors
        - text matrix that changes based on QFlags
        - grid layout of push buttons that follow enum matrix values and change colors
        - bool object connected to painted screen with typed in coordinates
        - current solution: bool object connected to painted screen with mouse-clicked spots
3. Managing the memory and runtime of the program for the pointers
    - My program kept crashing because I wasn't keeping careful enough track of pointers and my program's memory allocation; I didn't want to use RAII and risk confusing myself or worsening the program, so my final solution was to hard-code in multiple delete statements where I thought necessary to make sure that there weren't an unnecessary amount of heap objects at any given point.
4. Making sure version control was working properly with the files
    - Qt Creator has been hard to work with for me, possibly an error in downloading the files and installing the application, so I had trouble with both the https and ssh connections to Github from my files. I eventually had to completely reinstall Qt and make a new SSH key for everything to finally work properly

My program, although it works exactly as it should now, did fall short of my own expectations. I had intended for the program to mimic the game behavior of the website https://playgameoflife.com, meaning a zoom function, an adjustable timer, and predrawn board settings. I had decided earlier not to do the zoom function or the predrawn boards, but I thought the adjustable timer would be easy; it would just require a QSlider and a written function. Like I said before though, my main problem was connecting the slider properly; eventually, it was taking too much time and effort so I decided not to put in the adjustable timer as well. Despite this, I did learn much about the QSlider class and I have a better grasp on the difficulty of coding certain things in Qt, which will come in handy if I use Qt again.

Main improvements:
    - Would like to add the three aforementioned parts (zoom, timer, predrawn boards)
    - Would like to add user-input color customization

Although I didn't use any algorithms, as I wasn't experienced enough with them, I did get the chance to use lambda functions in the program, especially for all of the connect statements, something I learned from going over the discussion noted again.
