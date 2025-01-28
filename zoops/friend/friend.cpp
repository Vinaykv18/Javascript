#include <iostream>
using namespace std;

class BaseWithFriend {
private:
    int privateData;
public:
    //int privateData;
    BaseWithFriend() {
        privateData = 10;
    }
    friend class FriendClass;
};
class FriendClass : public BaseWithFriend{
public:
    void showPrivateData(BaseWithFriend& b) {
        cout << "Private Data: " << b.privateData << endl;
    }
};
int main() {
    BaseWithFriend bwf;
    FriendClass fc;
    fc.showPrivateData(bwf);

    return 0;
}
