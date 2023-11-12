#include <iostream>
#include "bullandcow.h"
#include <map>

const std::string HIDDEN_WORD = "heat";

BullCowGame::BullCowGame() {
    reset();
}

void BullCowGame::reset() {
    myCurrentTry = 1;
    gameIsWon = false;
    myHiddenWord = HIDDEN_WORD;
}

bool BullCowGame::isGameWon() const {
    return gameIsWon;
}

int BullCowGame::getMaxTries() const {
    return myHiddenWord.length() * 2;
}

int BullCowGame::getCurrentTry() const {
    return myCurrentTry;
}

int BullCowGame::getHiddenWordLength() const {
    return myHiddenWord.length();
}

GuessStatus BullCowGame::checkGuessValidity(const std::string& guess) const {
    if (!isIsogram(guess)) {
        return GuessStatus::NotIsogram;
    } else if (!isLowerCase(guess)) {
        return GuessStatus::NotLowercase;
    } else if (guess.length() != getHiddenWordLength()) {
        return GuessStatus::WrongLength;
    } else {
        return GuessStatus::OK;
    }
}

BullCowCount BullCowGame::submitValidGuess(const std::string& guess) {
    myCurrentTry++;
    BullCowCount bullCowCount;
    int wordLength = myHiddenWord.length();

    for (int i=0; i<wordLength; i++) {
        for (int j=0; j<wordLength; j++) {
            if (myHiddenWord[i] == guess[j]) {
                if (i == j) {
                    bullCowCount.bulls++;
                } else {
                    bullCowCount.cows++;
                }
            }
        }
    }

    if (bullCowCount.bulls == wordLength) {
        gameIsWon = true;
    } else {
        gameIsWon = false;
    }

    return bullCowCount;
}

bool BullCowGame::isIsogram(const std::string& guess) const {
    std::map<char,bool> letterSeen;
    for (auto letter: guess) {
        letter = tolower(letter);

        if (!letterSeen[letter]) {
            letterSeen[letter] = true;
        } else {
            return false;
        }
    }

    return true;
}

bool BullCowGame::isLowerCase(const std::string& guess) const {
    for (auto letter: guess) {
        if (!islower(letter)) {
            return false;
        }
    }

    return true;
}
