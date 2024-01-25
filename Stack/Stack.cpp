#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;
class QueueRing
{
    //Очередь
    int* Wait;
    //Максимальный размер очереди
    int MaxQueueLength;
    //Текущий размер очереди
    int QueueLength;
public:
    //Конструктор
    QueueRing(int m);
    //Деструктор
    ~QueueRing();
    //Добавление элемента
    void Add(int c);
    //Извлечение элемента
    bool Extract();
    //Очистка очереди
    void Clear();
    //Проверка существования элементов в очереди
    bool IsEmpty();
    //Проверка на переполнение очереди
    bool IsFull();
    //Количество элементов в очереди
    int GetCount();
    //демонстрация очереди
    void Show();
    bool Check(const QueueRing& second, const QueueRing& third);
    bool Random();
};

bool QueueRing::Random() 
{

    int randomScrolling = rand() % 5 + 1;
    cout << " " << randomScrolling;
    for (int i = 0; i < randomScrolling; i++) 
    {
        Extract();
    }
    return true;
}


bool QueueRing::Check(const QueueRing& second, const QueueRing& third) 
{

    for (int i = 0; i < QueueLength; i++) {
        if (Wait[i] == second.Wait[i] && Wait[i] == third.Wait[i] && second.Wait[i] == third.Wait[i]) {
            cout << " Chance " << i + 1 << " line: " << Wait[i] << " " << second.Wait[i] << " " << third.Wait[i] << endl;
            return true;
        }
    }
    return false;
}

void QueueRing::Show() 
{
    cout << "\n-----------------------------------\n";
    //демонстрация очереди
    for (int i = 0;i < QueueLength;i++) 
    {
        cout << Wait[i] << " ";
    }
    cout << "\n-------------------------------------\n";
}
QueueRing::~QueueRing()
{
    //удаление очереди
    delete[]Wait;
}
QueueRing::QueueRing(int m)
{
    //получаем размер
    MaxQueueLength = m;
    //создаем очередь
    Wait = new int[MaxQueueLength];
    //Изначально очередь пуста
    QueueLength = 0;
}
void QueueRing::Clear()
{
    //Эффективная "очистка" очереди
    QueueLength = 0;
}
bool QueueRing::IsEmpty()
{
    //Пуст?
    return QueueLength == 0;
}
bool QueueRing::IsFull()
{
    // Полон?
    return QueueLength == MaxQueueLength;
}

int QueueRing::GetCount()
{
    //Количество присутствующих в стеке элементов 
    return QueueLength;
}
void QueueRing::Add(int c)
{
    //Если в очереди есть свободное место, 
    //то увеличиваем количество
    //значений и вставляем новый элемент 
    if (!IsFull())
        Wait[QueueLength++] = c;
}
bool QueueRing::Extract()
{
    //Если в очереди есть элементы, то возвращаем тот,
    //который вошел первым и сдвигаем очередь 
    if (!IsEmpty()) 
    {
        //запомнить первый
        int temp = Wait[0];
        //сдвинуть все элементы
        for (int i = 1;i < QueueLength;i++)
            Wait[i - 1] = Wait[i];
        //забрасываем первый "вытолкнутый элемент
        //в конец"
        Wait[QueueLength - 1] = temp;
        return 1;
    }
    else return 0;
}

void main()
{
    srand(time(0));
    QueueRing first(5);
    QueueRing second(5);
    QueueRing third(5);

    for (int i = 0; i < 5; i++) 
    {
        first.Add(rand() % 3 + 1);
        second.Add(rand() % 3 + 1);
        third.Add(rand() % 3 + 1);
    }
    if (first.Check(second, third)) 
    {
        cout << " Pobeda" << endl;
    }
    else {
        cout << " Proigral" << endl;
    }

}


