#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void printList(Node *q) {
    while(q != NULL) {
        cout << q->data << endl;
        q = q->next;
    }
}

void insertAtTheFront(Node **birinci,int k) {
    Node *newNode = new Node();
    newNode->data = k;
    
    newNode->next = *birinci;
    *birinci = newNode;
}

void insertAtTheEnd(Node **birinci,int k) {
    Node *newNode = new Node();
    newNode->data = k;
    newNode->next = NULL;

    if(*birinci == NULL) {
        *birinci = newNode;
        return;
    }

    Node *last = *birinci;
    while(last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void insertAfter(Node *previous,int k) {
    Node *newNode = new Node();
    newNode->data = k;

    if(previous == NULL) {
        cout << "The previous node can not be NULL" << endl;
    }

    newNode->next = previous->next;
    previous->next = newNode;
}

float ortalamaAl(Node *head) {
    int sayac = 0;
    int sum = 0;
    Node *current = head;

    if(head == NULL)
        cout << "The list is empty" << endl;

    while(current != NULL) {
        sum += current->data;
        sayac++;
        current = current->next;
    }

    return static_cast<float>(sum)/ sayac;
}

int enkucukIkinci(Node *head) {
    Node *current = head;
    int min = INT_MAX;
    int secondMin = INT_MAX;
    if(head == NULL || head->next == NULL) {
        cout << "The list is empty" << endl;
        return INT_MIN;
    }
    

    while(current != NULL) {
        if(current->data < min) {
            secondMin = min;
            min = current->data;
        } else if (current->data < secondMin && current->data != min) {
                secondMin = current->data;
        }
        current = current->next;
    }

    return secondMin;
}

float kdanKucukseToplaCarp (Node *head,int k,int &sum,int &product){
    Node *gezici = head;
    sum = 0;
    product = 1;

    if(head == NULL) {
        cout << "Listede eleman yok" << endl;
        return 0;
    }

    while(gezici != NULL) {
        if(gezici->data < k ) {
            sum+=gezici->data;
            product*=gezici->data;

        }
        gezici = gezici->next;
    }
    return static_cast<float>(sum) + static_cast<float>(product);

}

int findMax(Node *head) {
    Node *gezici = head;

    // Boş olma durumunu kontrol et
    if (head == NULL) {
        cout << "The list is empty" << endl;
        return 0;
    }

    int max = head->data;

    while(gezici != NULL) {
        if(gezici->data > max) {
            max = gezici->data;
        }
        gezici = gezici->next;
    }
        return max;
}

int findMin(Node *head) {
    Node *gezici = head;

    // Boş olma durumunu kontrol et
    if (head == NULL) {
        cout << "The list is empty" << endl;
    }

    int min = head->data;
    
    while(gezici != NULL) {
        if(gezici->data < min) {
            min = gezici->data;
        }
        gezici = gezici->next;
    }
    
    return min;
}

int teksayilarinToplami(Node *head) {
    Node *gezici = head;

    // Boş olma durumunu kontrol et
    if (head == NULL) {
        cout << "The list is empty" << endl;
    }

    int tekToplam = 0;

    while (gezici != NULL) {
        if(gezici->data % 2 != 0) {
            tekToplam += gezici->data;
        }
            gezici = gezici->next;
    }
    
    return tekToplam;
}

int main() {

    Node *birinci = new Node();
    Node *ikinci = new Node();
    Node *ucuncu = new Node();
    birinci->data = 1;
    ikinci->data = 2;
    ucuncu->data = 3;
    birinci->next = ikinci;
    ikinci->next = ucuncu;

    insertAtTheFront(&birinci,-1);
    insertAtTheEnd(&birinci,4);
    insertAfter(ikinci,5);
    printList(birinci);

    float ortalama = ortalamaAl(birinci);
    cout << "Ortalama : " << ortalama << endl; 

    int minimum = enkucukIkinci(birinci);
    cout << "En kucuk ikinci eleman :" << minimum << endl;

    int k = 3;
    int sum = 0;
    int product = 1;
    kdanKucukseToplaCarp(birinci,3,sum,product);
    cout << k << " sayisindan kucuk olan sayilarin toplami :" << sum << endl;
    cout << k << " sayisindan kucuk olan sayilarin carpimi :" << product << endl;

    int maximum = findMax(birinci);
    cout << "En buyuk deger : " << maximum << endl;

     
    int minimum1 = findMin(birinci);
    cout << "En kucuk deger : " << minimum1 << endl;

    int tekToplam = teksayilarinToplami(birinci);
    cout << "Tek sayilarin toplami : " << tekToplam << endl;
    
    
    
    // Belleği temizle
    while (birinci != NULL) {
        Node* temp = birinci;
        birinci = birinci->next;
        delete temp;
    }
}