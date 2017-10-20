#include <iostream>
#include <string>
#include <map>

using namespace std;

class Message{
private:
    string value;
    int classification;
public:
    void setValue(const string value);
    string getValue () const;
    void setClassification(const int value);
    int getClassification() const;
    void operator++();

    friend std::ostream &operator<<(std::ostream &stream, Message &obj) {
        //stream = new cout
        //stream << "Bla" << endl;
        stream << "==========================" << endl;
        stream << "Value: " << obj.value << endl;
        stream << "Classification: " << obj.classification << endl;
        return stream;
    }
};

void Message::setValue(const string value){
    this->value = value;
}
string Message::getValue ()const {
    return this->value;
}
void Message::setClassification(const int value){
    this->classification = value;
}
int Message::getClassification() const {
    return this->classification;
}

void Message::operator++() {
    this->classification++;
}

class Classifier{
public:
    static Message * classifyMessage(string *messages, int size);
};

Message* Classifier::classifyMessage(string *messages, int size) {
    Message *obj = new Message [size];
    string keyWords[3]{"cash" , "sales" , "marketing"};
    int counter = 0;
    map<string, int> uniqueMessage;

    // Count strings
    for(int i = 0; i < size; i++) {
        if(uniqueMessage[messages[i]] < 2)uniqueMessage[messages[i]]++;
    }

    for(int i = 0; i < size; i++){
        obj[i].setValue(messages[i]);
        obj[i].setClassification(0);
        //Check string length
        if(messages[i].size() < 12){
            ++obj[i];
        }
        //check doubles
        if(uniqueMessage[messages[i]] > 1){
            ++obj[i];
        }
        // Search
        size_t found;
        for(int j = 0; j < 3; j++){
            found = messages[i].find(keyWords[j]);
            if(found != string::npos){
                ++obj[i];
                break;
            }
        }
    }
    return obj;
}

int main() {
    const int n = 5;
    string *messages = new string [n];
    //Generate Test String
    for(int i = 0; i < n; i++){
        messages[i] = "sales";
    }

    Message *bla = Classifier::classifyMessage(messages, n);

    for (int i = 0; i < n; i++){
        cout << bla[i];
    }


    return 0;
}