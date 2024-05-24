#include "animate.h"
#include "constants.h"
#include <iostream>
#include <string> 
using namespace std;
#include "system.h"

animate::animate() : sidebar(WORK_PANEL, SIDE_BAR), g(new Graph_info())

{
    cout << "animate CTOR: TOP" << endl;
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
    // VideoMode class has functions to detect screen size etc.
    // RenderWindow constructor has a third argumnet to set style
    // of the window: resize, fullscreen etc.

    // System will be implemented to manage a vector of objects to be animated.
    //   at that point, the constructor of the System class will take a vector
    //   of objects created by the animate object.
    //   animate will
    system = System(g);
    window.setFramerateLimit(60);

    mouseIn = true;

    mousePoint = sf::CircleShape();
    mousePoint.setRadius(5.0);
    mousePoint.setFillColor(sf::Color::Red);

    cout << "Geme CTOR. preparing to load the font." << endl;
    //--- FONT ----------
    // font file must be in the "working directory:
    //      debug folder
    // Make sure working directory is where it should be and not
    //  inside the app file:
    //  Project->RUN->Working Folder
    //
    // font must be a member of the class.
    //  Will not work with a local declaration
    if (!font.loadFromFile("arial.ttf"))
    {
        cout << "animate() CTOR: Font failed to load" << endl;
        cin.get();
        exit(-1);
    }

    cout << "animate instantiated successfully." << endl;
    
    input.setFont(font);
    input.setCharacterSize(30);
    input.setFillColor(sf::Color(110,110,238));
    input.setOrigin(0, 0);
    input.setPosition(20, SCREEN_HEIGHT - input.getCharacterSize() - 35); //20 is the xscreen coord and charsize is the size of the char - 35 (height) (the bigger the higher)
            // instream.open("history.txt");
            // if(instream.fail()){
            //     cout << "Error: Failed to open!!" << endl;
            //     exit(1);
            // }
            // history.clear();
            // instream >> n;
            // instream.ignore();
            // for (int i = 0; i < n; i++){
            //     string str;
            //     getline(instream,str);
            //     //cout << "woohoo" << endl;
            //     // cout << "Read line: " << str << endl;
            //     history.push_back(str);
            //     str.clear();
            // }
            // instream.close();
            // //end of files 
            // sidebar._history(history);
}

void animate::Draw()
{
    // Look at the data and based on the data, draw shapes on window object.
    system.Draw(window);
    
    if (mouseIn)
    {
        window.draw(mousePoint);
    }
    
    sidebar.draw(window);
    //adding my own
    // sidebar.draw(window);

    //- - - - - - - - - - - - - - - - - - -
    // getPosition() gives you screen coords, getPosition(window) gives you window coords
    // cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
    //- - - - - - - - - - - - - - - - - - -

    // drawing Test: . . . . . . . . . . . .
    // This is how you draw text:)
    window.draw(myTextLabel);
    window.draw(input);
}

void animate::update()
{
    system.Step(command,g); 
    command = 0;
    if (mouseIn)
    {
        // if (mousePoint.getPosition == sf::Mouse(SCREEN_WIDTH - WORK_PANEL),input.height += sb_text.getLocalBounds().height + VERTICAL_LINE_SPACING;)
        // // mousePoint red dot:

        // mousePoint.setPosition(sf::Mouse::getPosition(window).x - 5,
        //                        sf::Mouse::getPosition(window).y - 5);
        // if(mousePoint.getPosition()){

        // }
        // sf::Vector2f pos = mousePoint.getPosition();
        // if ((pos.x == SCREEN_WIDTH - WORK_PANEL) && pos.y == (SCREEN_HEIGHT + input.getCharacterSize())){
        //     cout << "yas " << endl;
        // }
        // mouse location text for sidebar:
        //sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
    }
}
void animate::render()
{
    window.clear();
    Draw();
    window.display();

}

void animate::processEvents()
{
    sf::Event event;
    float mouseX, mouseY;
    while (window.pollEvent(event)) // or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        // window closed
        case sf::Event::Closed:
            window.close();
            break;

        // key pressed
        case sf::Event::KeyPressed:
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
            window.close();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            //sidebar[SB_KEY_PRESSED] = "Panning left";
            command = 4;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            //sidebar[SB_KEY_PRESSED] = "Panning right";
            command = 6;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            //sidebar[SB_KEY_PRESSED] = "Panning up";
            command = 10;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            //sidebar[SB_KEY_PRESSED] = "Panning down";
            command = 12;
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)){
             if (istyping){
                //don't do anything 
            }
            else{
            //sidebar[SB_KEY_PRESSED] = "Zooming in ";
            command = 14;
            }
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen)) {
            if (istyping){
                //don't do anything 
            }
            else{
                //sidebar[SB_KEY_PRESSED] = "Zooming out ";
                command = 16;
            }
        }
        // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
        //     if (istyping){
        //         //don't do anything 
        //     }
        //     else{
        //     sidebar[SB_KEY_PRESSED] = "Reset";
        //     command = 18;
        //     }
        // }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
            if (user_input.empty()){   //if user presses enter w/o typing anything, js shows default graph
                g->_equation = "tan(x)";
                command == 300;
            }
            else{
            g->_equation = user_input;
            history.push_back(user_input);
            //files 
            outstream.open("history.txt");
            if(outstream.fail()){
                cout << "Error: Failed to open!!" << endl;
                exit(1);
            }
            int n = history.size();
            outstream << n << endl;
            for (int i = 0; i< history.size(); i++){
                outstream << history[i] << endl;
            }
            //history.clear();
            outstream.close();
            // int n = history.size();
            // for (int i = 0; i< history.size(); i++){
            //     outstream << history[i] << endl;
            // }
            // //history.clear();
            // outstream.close();

            instream.open("history.txt");
            if(instream.fail()){
                cout << "Error: Failed to open!!" << endl;
                exit(1);
            }
            history.clear();
            instream >> n;
            instream.ignore();
            for (int i = 0; i < n; i++){
                string str;
                getline(instream,str);
                //cout << "woohoo" << endl;
                // cout << "Read line: " << str << endl;
                history.push_back(str);
                str.clear();
            }
            instream.close();
            //end of files 
            sidebar._history(history);
            //sidebar.draw(window);
            // sidebar[SB_KEY_PRESSED] = g->_equation;
            command = 300;  //random number 
            user_input.clear();   //clear the string for next eq
            istyping = false;
        }
        }
            break;
        case sf::Event::MouseEntered:
            mouseIn = true;
            break;

        case sf::Event::MouseLeft:
            mouseIn = false;
            break;

        case sf::Event::MouseMoved:
            mouseX = event.mouseMove.x;
            mouseY = event.mouseMove.y;
            mousex = mouseX;
            mousey = mouseY;
            // Do something with it if you need to...
            break;

        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                if ((mousex >= sidebar.pos.x && mousey <= SCREEN_HEIGHT+ sidebar.pos.y)){
                    const double firstbox = sidebar.getHeight();
                    double i=1;
                    i = mousey/firstbox;
                    int vector_pos = static_cast<int>(std::round(i));
                    if (vector_pos > history.size()){
                        // g->_equation = "tan(x)";
                    }
                    else{
                    g->_equation = history[vector_pos];
                    }
                }  
            }
            else
            {
                if ((mousex >= sidebar.pos.x && mousey <= SCREEN_HEIGHT+ sidebar.pos.y)){
                    const double firstbox = sidebar.getHeight();
                    //double i=1;
                    double i = mousey/(firstbox);
                    int vector_pos = static_cast<int>(std::round(i));
                    if (vector_pos > history.size()){
                        // g->_equation = "tan(x)";
                    }
                    else{
                    g->_equation = history[vector_pos];
                    }
                }
            } 
            break;

        case sf::Event::TextEntered:
            if (event.text.unicode < 128)
            {
             istyping = true;
             if (event.text.unicode == 45 && user_input.empty()){
                istyping = false;   //want to zoom out 45-> hyphen (-)
             }
             else if(event.text.unicode == 61){
                istyping = false;   //want to zoom in 61 -> equal (+/=)
             }
            else if(event.text.unicode == 114){
                istyping = false;   //want to zoom in 61 -> equal (+/=)
             }
             else{
                if (event.text.unicode == 8){ //backspace
                    if (!user_input.empty()){
                        user_input.pop_back();
                    }
                }
                if (event.text.unicode != 8 && event.text.unicode != 13){ //not backspace OR ENTER APPARENTLY
                    char _char = static_cast<char>(event.text.unicode);
                    user_input += _char;
                }
            }
            input.setString(user_input);
            }
            break;

        default:
            break;
        } 
    }
}

void animate::run()
{
    while (window.isOpen())
    {
        processEvents();
        update(); 
        render(); // clear/draw/display
    }
    cout << endl
         << "-------ANIMATE MAIN LOOP EXITING ------------" << endl;
}

string mouse_pos_string(sf::RenderWindow &window)
{
    return "(" +
           to_string(sf::Mouse::getPosition(window).x) +
           ", " +
           to_string(sf::Mouse::getPosition(window).y) +
           ")";
}
// #include "animate.h"
// #include "constants.h"
// #include <iostream>
// #include <string> 
// using namespace std;
// #include "system.h"

// animate::animate() : sidebar(WORK_PANEL, SIDE_BAR), g(new Graph_info())

// {
//     cout << "animate CTOR: TOP" << endl;
//     window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML window!");
//     // VideoMode class has functions to detect screen size etc.
//     // RenderWindow constructor has a third argumnet to set style
//     // of the window: resize, fullscreen etc.

//     // System will be implemented to manage a vector of objects to be animated.
//     //   at that point, the constructor of the System class will take a vector
//     //   of objects created by the animate object.
//     //   animate will
//     system = System(g);
//     window.setFramerateLimit(60);

//     mouseIn = true;

//     mousePoint = sf::CircleShape();
//     mousePoint.setRadius(5.0);
//     mousePoint.setFillColor(sf::Color::Red);

//     cout << "Geme CTOR. preparing to load the font." << endl;
//     //--- FONT ----------
//     // font file must be in the "working directory:
//     //      debug folder
//     // Make sure working directory is where it should be and not
//     //  inside the app file:
//     //  Project->RUN->Working Folder
//     //
//     // font must be a member of the class.
//     //  Will not work with a local declaration
//     if (!font.loadFromFile("arial.ttf"))
//     {
//         cout << "animate() CTOR: Font failed to load" << endl;
//         cin.get();
//         exit(-1);
//     }

//     cout << "animate instantiated successfully." << endl;
    
//     input.setFont(font);
//     input.setCharacterSize(30);
//     input.setFillColor(sf::Color(110,110,238));
//     input.setOrigin(0, 0);
//     input.setPosition(20, SCREEN_HEIGHT - input.getCharacterSize() - 35); //20 is the xscreen coord and charsize is the size of the char - 35 (height) (the bigger the higher)

            // instream.open("history.txt");
            // if(instream.fail()){
            //     cout << "Error: Failed to open!!" << endl;
            //     exit(1);
            // }
            // history.clear();
            // instream >> n;
            // instream.ignore();
            // for (int i = 0; i < n; i++){
            //     string str;
            //     getline(instream,str);
            //     //cout << "woohoo" << endl;
            //     // cout << "Read line: " << str << endl;
            //     history.push_back(str);
            //     str.clear();
            // }
            // instream.close();
            // //end of files 
            // sidebar._history(history);
// }

// void animate::Draw()
// {
//     // Look at the data and based on the data, draw shapes on window object.
//     system.Draw(window);
    
//     if (mouseIn)
//     {
//         window.draw(mousePoint);
//     }
    
//     sidebar.draw(window);
//     //adding my own
//     // sidebar.draw(window);

//     //- - - - - - - - - - - - - - - - - - -
//     // getPosition() gives you screen coords, getPosition(window) gives you window coords
//     // cout<<"mosue pos: "<<sf::Mouse::getPosition(window).x<<", "<<sf::Mouse::getPosition(window).y<<endl;
//     //- - - - - - - - - - - - - - - - - - -

//     // drawing Test: . . . . . . . . . . . .
//     // This is how you draw text:)
//     window.draw(myTextLabel);
//     window.draw(input);
// }

// void animate::update()
// {
//     system.Step(command,g); 
//     command = 0;
//     if (mouseIn)
//     {
//         // if (mousePoint.getPosition == sf::Mouse(SCREEN_WIDTH - WORK_PANEL),input.height += sb_text.getLocalBounds().height + VERTICAL_LINE_SPACING;)
//         // // mousePoint red dot:

//         // mousePoint.setPosition(sf::Mouse::getPosition(window).x - 5,
//         //                        sf::Mouse::getPosition(window).y - 5);
//         // if(mousePoint.getPosition()){

//         // }
//         // sf::Vector2f pos = mousePoint.getPosition();
//         // if ((pos.x == SCREEN_WIDTH - WORK_PANEL) && pos.y == (SCREEN_HEIGHT + input.getCharacterSize())){
//         //     cout << "yas " << endl;
//         // }
//         // mouse location text for sidebar:
//         //sidebar[SB_MOUSE_POSITION] = mouse_pos_string(window);
//     }
// }
// void animate::render()
// {
//     window.clear();
//     Draw();
//     window.display();

// }

// void animate::processEvents()
// {
//     sf::Event event;
//     float mouseX, mouseY;
//     while (window.pollEvent(event)) // or waitEvent
//     {
//         // check the type of the event...
//         switch (event.type)
//         {
//         // window closed
//         case sf::Event::Closed:
//             window.close();
//             break;

//         // key pressed
//         case sf::Event::KeyPressed:
//         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//             sidebar[SB_KEY_PRESSED] = "ESC: EXIT";
//             window.close();
//         }
//         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//             //sidebar[SB_KEY_PRESSED] = "Panning left";
//             command = 4;
//         }
//         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
//             //sidebar[SB_KEY_PRESSED] = "Panning right";
//             command = 6;
//         }
//         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
//             //sidebar[SB_KEY_PRESSED] = "Panning up";
//             command = 10;
//         }
//         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
//             //sidebar[SB_KEY_PRESSED] = "Panning down";
//             command = 12;
//         }
//         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Equal)){
//              if (istyping){
//                 //don't do anything 
//             }
//             else{
//             //sidebar[SB_KEY_PRESSED] = "Zooming in ";
//             command = 14;
//             }
//         }
//         else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Hyphen)) {
//             if (istyping){
//                 //don't do anything 
//             }
//             else{
//                 //sidebar[SB_KEY_PRESSED] = "Zooming out ";
//                 command = 16;
//             }
//         }
//         // else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)){
//         //     if (istyping){
//         //         //don't do anything 
//         //     }
//         //     else{
//         //     sidebar[SB_KEY_PRESSED] = "Reset";
//         //     command = 18;
//         //     }
//         // }
//         else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)){
//             if (user_input.empty()){   //if user presses enter w/o typing anything, js shows default graph
//                 g->_equation = "tan(x)";
//                 command == 300;
//             }
//             else{
//             g->_equation = user_input;
//             history.push_back(user_input);
//             //files 
//             outstream.open("history.txt");
//             if(outstream.fail()){
//                 cout << "Error: Failed to open!!" << endl;
//                 exit(1);
//             }
            // int n = history.size();
            // outstream << n << endl;
            // for (int i = 0; i< history.size(); i++){
            //     outstream << history[i] << endl;
            // }
            // //history.clear();
            // outstream.close();

//             instream.open("history.txt");
//             if(instream.fail()){
//                 cout << "Error: Failed to open!!" << endl;
//                 exit(1);
//             }
//             history.clear();
//             instream >> n;
//             instream.ignore();
//             for (int i = 0; i < n; i++){
//                 string str;
//                 getline(instream,str);
//                 //cout << "woohoo" << endl;
//                 // cout << "Read line: " << str << endl;
//                 history.push_back(str);
//                 str.clear();
//             }
//             instream.close();
//             //end of files 
//             sidebar._history(history);
//             //sidebar.draw(window);
//             // sidebar[SB_KEY_PRESSED] = g->_equation;
//             command = 300;  //random number 
//             user_input.clear();   //clear the string for next eq
//             istyping = false;
//         }
//         }
//             break;
//         case sf::Event::MouseEntered:
//             mouseIn = true;
//             break;

//         case sf::Event::MouseLeft:
//             mouseIn = false;
//             break;

//         case sf::Event::MouseMoved:
//             mouseX = event.mouseMove.x;
//             mouseY = event.mouseMove.y;
//             mousex = mouseX;
//             mousey = mouseY;
//             // Do something with it if you need to...
//             break;

//         case sf::Event::MouseButtonReleased:
//             if (event.mouseButton.button == sf::Mouse::Right)
//             {
//                 if ((mousex >= sidebar.pos.x && mousey <= SCREEN_HEIGHT+ sidebar.pos.y)){
//                     const double firstbox = sidebar.getHeight();
//                     double i=1;
//                     i = mousey/firstbox;
//                     int vector_pos = static_cast<int>(std::round(i));
//                     if (vector_pos > history.size()){
//                         // g->_equation = "tan(x)";
//                     }
//                     else{
//                     g->_equation = history[vector_pos];
//                     }
//                 }  
//             }
//             else
//             {
//                 if ((mousex >= sidebar.pos.x && mousey <= SCREEN_HEIGHT+ sidebar.pos.y)){
//                     const double firstbox = sidebar.getHeight();
//                     double i=1;
//                     i = mousey/firstbox;
//                     int vector_pos = static_cast<int>(std::round(i));
//                     if (vector_pos > history.size()){
//                         // g->_equation = "tan(x)";
//                     }
//                     else{
//                     g->_equation = history[vector_pos];
//                     }
//                 }
//             } 
//             break;

//         case sf::Event::TextEntered:
//             if (event.text.unicode < 128)
//             {
//              istyping = true;
//              if (event.text.unicode == 45 && user_input.empty()){
//                 istyping = false;   //want to zoom out 45-> hyphen (-)
//              }
//              else if(event.text.unicode == 61){
//                 istyping = false;   //want to zoom in 61 -> equal (+/=)
//              }
//             else if(event.text.unicode == 114){
//                 istyping = false;   //want to zoom in 61 -> equal (+/=)
//              }
//              else{
//                 if (event.text.unicode == 8){ //backspace
//                     if (!user_input.empty()){
//                         user_input.pop_back();
//                     }
//                 }
//                 if (event.text.unicode != 8 && event.text.unicode != 13){ //not backspace OR ENTER APPARENTLY
//                     char _char = static_cast<char>(event.text.unicode);
//                     user_input += _char;
//                 }
//             }
//             input.setString(user_input);
//             }
//             break;

//         default:
//             break;
//         } 
//     }
// }

// void animate::run()
// {
//     while (window.isOpen())
//     {
//         processEvents();
//         update(); 
//         render(); // clear/draw/display
//     }
//     cout << endl
//          << "-------ANIMATE MAIN LOOP EXITING ------------" << endl;
// }

// string mouse_pos_string(sf::RenderWindow &window)
// {
//     return "(" +
//            to_string(sf::Mouse::getPosition(window).x) +
//            ", " +
//            to_string(sf::Mouse::getPosition(window).y) +
//            ")";
// }





