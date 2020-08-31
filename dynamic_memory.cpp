#include <memory>
#include <iostream>

using namespace std;

shared_ptr<int> factory(int x) {
    return make_shared<int>(x);
}

void print(weak_ptr<int> wptr) {
    if (!wptr.expired()) {
        cout << "Weak pointer : " << *wptr.lock() << ", expired: " << boolalpha << wptr.expired() << endl;
    } else {
        cout << "Weak pointer already expired" << endl;
    }
}

int main() {
    auto p0 = factory(10);
    cout << "Use Count : " << p0.use_count() << endl;
    weak_ptr<int> wp0(p0);
    print(wp0);
    p0.reset();
    cout << "After deletion" << endl;
    cout << "Use Count : " << p0.use_count() << endl;
    print(wp0);

    return 0;
}