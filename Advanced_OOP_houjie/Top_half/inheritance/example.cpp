#include <iostream>

class CDocument {
public:
    void OnFileOpen(){
        std::cout << "Open file" << '\n';
        Serialize();
        std::cout << "Close file" << '\n';
    }
    virtual void Serialize() {}
};

class CMyDoc : public CDocument {
public:
    virtual void Serialize() {
        std::cout << "Open Doc" << '\n';
    }
};

int main()
{
    CMyDoc mydoc;
    mydoc.OnFileOpen();
}