#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "shplexicon.h"

using namespace std;
using namespace sf;

string getStringFromSet(const set<string> & suggestions) {
    string temp;
    for (string sugg : suggestions)
        temp += sugg + " ";
    return temp;
}

int main() {
    srand(time(nullptr));
    RenderWindow window(VideoMode(640,480,32),"Spell Checker");

    Font font;
    font.loadFromFile("resources/fonts/Courier New.ttf");
    Text label;
    label.setFont(font);
    label.setCharacterSize(32);
    label.setString("");
    label.setPosition(window.getSize().x/2 - label.getGlobalBounds().width/2,
                     window.getSize().y/2 - label.getGlobalBounds().height/2);
    label.setFillColor(Color::Black);

    Text topLabel;
    topLabel.setFont(font);
    topLabel.setCharacterSize(14);
    topLabel.setPosition(0, 14);
    topLabel.setFillColor(Color::Black);
    /*
    Text suggestionLabel;
    suggestionLabel.setFont(font);
    suggestionLabel.setCharacterSize(14);
    suggestionLabel.setPosition(0, 450);
    suggestionLabel.setFillColor(Color(50, 50, 50));
    suggestionLabel.setString("Hello world");
    */
    shplexicon words;
    ifstream fin("words.txt");
    string word;
    while (!fin.eof()) {
        fin >> word;
        words.insert(word);
    }

    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)) {
            if(event.type == Event::Closed){
                window.close();
            } else if (event.type == Event::TextEntered) {
                    char ch = static_cast<char>(event.text.unicode);
                    if (ch == ' ' || ch == '\n') {
                        topLabel.setString(topLabel.getString() + " " + label.getString());
                        if (topLabel.getLocalBounds().width > window.getSize().x)
                            topLabel.setString(label.getString());
                        label.setString("");

                    }
                    else if (ch == 127 || ch == 8) {
                        string str = label.getString();
                        label.setString(str.substr(0, str.length()-1));
                    } else {
                        label.setString(label.getString() + ch);
                        /*set<string> suggestions = words.getWordsWithPrefix(label.getString());
                       if (suggestions.size() <= 10)
                           suggestionLabel.setString(getStringFromSet(suggestions));
                           else
                        suggestionLabel.setString("Number of suggestions = " + to_string(suggestions.size()));
                        */
                         }
                        label.setPosition(window.getSize().x/2 - label.getGlobalBounds().width/2,
                                  window.getSize().y/2 - label.getGlobalBounds().height/2);

            }
                    if (words.containsWord(label.getString()))
                        label.setFillColor(Color::Black);
                    else
                        label.setFillColor(Color::Red);
            }

            window.clear(Color::White);
            window.draw(topLabel);
            window.draw(label);
            //window.draw(suggestionLabel);
            window.display();
        }

    return 0;
}