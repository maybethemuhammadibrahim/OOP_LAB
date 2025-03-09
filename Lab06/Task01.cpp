
#include <iostream>
using namespace std;

class Message {
    private:
    string text;
    public:
    Message(string text) : text(text) {}

    string toString() {
        return text;
    }

    string getText() {
        return text;
    }

    void setText(string text) {
        this->text = text;
    }

};

class SMS : public Message {
    private:
    string receipientContactNo;
    public:
    SMS(string no, string text) : receipientContactNo(no), Message(text) {}

    string getReceipientContactNo() {
        return receipientContactNo;
    }

    void setReceipientContactNo(string no) {
        this->receipientContactNo = no;
    }

    string toString() {
        return (receipientContactNo + ' ' + getText());
    }


};

class Email : public Message {
    private:
    string sender;
    string receiver;
    string subject;

    public:
    Email(string sender, string receiver, string subject, string text) : sender(sender), receiver(receiver), subject(subject), Message(text) {}

    string getSender() {
        return sender;
    }
    string getReceiver() {
        return receiver;
    }
    string getSubject() {
        return subject;
    }

    void setSender(string sender) {
        this->sender = sender;
    }
    void setReceiver(string receiver) {
        this->receiver = receiver;
    }
    void setSubject(string subject) {
        this->subject = subject;
    }


    string toString() {
        return (sender + ' ' + receiver + ' ' + subject + ' ' + getText());
    }
};

bool containsKeyword(Message& msgobj, const string& keyword){
    string temp = msgobj.getText();
    int tempIndex = 0;
    bool doesContain;
    for(int i = 0; temp[i]!='\0' ; i++){
        if(temp[i]==keyword[tempIndex]) {  
            tempIndex++;
            if(keyword[tempIndex+1] == '\0'){
                return true;
            }
        }
        else {
            tempIndex = 0;
        }
    }
    return false;
}

void encode(Message& msgobj) {
    string temp = msgobj.getText();
    cout << "Encoding Message ->" << temp << endl;
    for(int i = 0; temp[i] != '\0' ; i++){
        if(temp[i]=='z'){
            temp[i] = 'a';
            // cout << "Debug1" << endl;
        }
        else if(temp[i] == 'Z'){
            temp[i] = 'A';
            // cout << "Debug2" << endl;
        }
        else if(temp[i] == ' '){
            temp[i] = ' ';
        }
        else{
            temp[i] = temp[i]+1;
            // cout << "Debug3" << endl;
        }
    }
    msgobj.setText(temp);
}

int main() {
    SMS s1("+92123456789", "This is Java");
    cout << s1.toString() << endl;
    cout << (containsKeyword(s1,"Java") ? "yes this contains the keyword": "No this does not contain the keyword") << endl;
    //encoding message
    encode(s1);
    cout << s1.getText() << endl;


    cout << endl;

    Email e1("Sender", "Receiver", "Subject", "This is Python");
    cout << e1.toString() << endl;
    cout << (containsKeyword(e1,"Java") ? "yes this contains the keyword": "No this does not contain the keyword") << endl;
    //encoding message
    encode(e1);
    cout << e1.getText() << endl;


}
