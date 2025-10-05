#include <iostream>
using namespace std;

// Node class — represents one card
class Node {
public:
    char suit;   // 'c', 's', 'h', 'd'
    int value;   // 1–13
    Node* next;

    Node(char s, int v) {
        suit = s;
        value = v;
        next = nullptr;
    }
};

// LinkedList class — manages player's deck
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Insert card at end
    void insertEnd(char suit, int value) {
        Node* newNode = new Node(suit, value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Remove first card and return pointer
    Node* removeFront() {
        if (head == nullptr)
            return nullptr;
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        return temp;
    }

    // Display all cards
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "(" << temp->suit << "," << temp->value << ") ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Deallocate memory
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

// CardGame class — manages the full game logic
class CardGame {
private:
    LinkedList player1;
    LinkedList player2;
    int points1, points2;
    int n;

    // Suit ranking
    int suitRank(char s) {
        switch (s) {
            case 'c': return 4; // Clubs strongest
            case 's': return 3;
            case 'h': return 2;
            case 'd': return 1; // Diamonds weakest
            default: return 0;
        }
    }

public:
    // Constructor
    CardGame() {
        points1 = points2 = 0;
        n = 0;
    }

    // Input cards
    void inputCards() {
        cout << "Enter number of cards for each player: ";
        cin >> n;

        cout << "\nEnter Player 1 cards (suit value):\n";
        for (int i = 0; i < n; i++) {
            char s; int v;
            cin >> s >> v;
            player1.insertEnd(s, v);
        }

        cout << "\nEnter Player 2 cards (suit value):\n";
        for (int i = 0; i < n; i++) {
            char s; int v;
            cin >> s >> v;
            player2.insertEnd(s, v);
        }
    }

    // Play game
    void playGame() {
        cout << "\nPlayer 1 cards: ";
        player1.display();
        cout << "Player 2 cards: ";
        player2.display();

        cout << "\n--- Game Starts ---\n";

        for (int i = 0; i < n; i++) {
            Node* c1 = player1.removeFront();
            Node* c2 = player2.removeFront();

            cout << "\nRound " << i + 1 << ": (" << c1->suit << "," << c1->value 
                 << ") vs (" << c2->suit << "," << c2->value << ") ";

            if (c1->suit == c2->suit) {
                if (c1->value > c2->value) {
                    points1++;
                    cout << "=> Player 1 wins this round!";
                } else if (c2->value > c1->value) {
                    points2++;
                    cout << "=> Player 2 wins this round!";
                } else {
                    cout << "=> Tie!";
                }
            } else {
                if (suitRank(c1->suit) > suitRank(c2->suit)) {
                    points1++;
                    cout << "=> Player 1 wins (higher suit)!";
                } else {
                    points2++;
                    cout << "=> Player 2 wins (higher suit)!";
                }
            }

            delete c1;
            delete c2;
        }
    }

    // Display final result
    void showResult() {
        cout << "\n\n--- Final Result ---\n";
        cout << "Player 1 Points: " << points1 << endl;
        cout << "Player 2 Points: " << points2 << endl;

        if (points1 > points2)
            cout << "🏆 Player 1 Wins!" << endl;
        else if (points2 > points1)
            cout << "🏆 Player 2 Wins!" << endl;
        else
            cout << "🤝 It's a Tie!" << endl;
    }
};

// Main function
int main() {
    CardGame game;
    game.inputCards();
    game.playGame();
    game.showResult();
    return 0;
}


