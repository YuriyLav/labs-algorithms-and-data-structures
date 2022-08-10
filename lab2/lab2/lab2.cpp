#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

vector<int> create_vec(int n)
{
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
        vec[i] = i;
    }
    return vec;
}
int min(int x, int y) { return (x <= y) ? x : y; } // функция для поиска минимум двух элементов
int fibMonaccianSearch(vector<int> arr, int x, int n) //Возвращает индекс x, если присутствует, иначе возвращает - 1
{   //Инициализация чисел Фибоначчи
    int fibMMm2 = 0; // (m-2)-ый номер Фибоначчи
    int fibMMm1 = 1; // (m-1)-ый номер Фибоначчи
    int fibM = fibMMm2 + fibMMm1; // m-ый номер Фибоначчи
    while (fibM < n) // Число больше или равно длине массива
    {
        fibMMm2 = fibMMm1; 
        fibMMm1 = fibM; 
        fibM = fibMMm2 + fibMMm1; 
    }
    int offset = -1; // Отмечает удаленный диапазон спереди
    while (fibM > 1) //пока есть элементы для проверки
    {
        int i = min(offset + fibMMm2, n - 1);
        if (arr[i] < x) //Если x больше значения arr[i], вырезать массив подмассива со смещением на i
        {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }
        else if (arr[i] > x)
        {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }
        else return i; //элемент найден
    }
    if (fibMMm1 && arr[offset + 1] == x) return offset + 1; //сравнение последнего элемента с x
    return -1; //элемент не найден возврат -1
}
int main()
{
    srand(time(NULL));
    int x = 5;
    int n1 = 10, n2=3500, n3=6000;
    vector <int> vec1(n1), vec2(n2), vec3(n3);
    vec1 = create_vec(n1); vec2 = create_vec(n2); vec3 = create_vec(n3);

    auto start = chrono::high_resolution_clock::now();
    /*cout<<(fibMonaccianSearch(vec1, x, n1));*/
    cout << endl;
for (vector<int>::iterator it = vec1.begin(); it != vec1.end(); ++it)
cout << *it << " ";
cout << endl;
    cout<<fibMonaccianSearch(vec1, x, n1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<float> duration = end - start;
    cout << endl << n1 << " - " << duration.count() << "s";

    //start = chrono::high_resolution_clock::now();
    ///*cout << (fibMonaccianSearch(vec2, x, n2));*/
    //fibMonaccianSearch(vec1, x, n1);
    //end = chrono::high_resolution_clock::now();
    //duration = end - start;
    //cout << endl << n2 << " - " << duration.count() << "s";

    //start = chrono::high_resolution_clock::now();
    ///*cout << (fibMonaccianSearch(vec3, x, n3));*/
    //fibMonaccianSearch(vec1, x, n1);
    //end = chrono::high_resolution_clock::now();
    //duration = end - start;
    //cout << endl << n3 << " - " << duration.count() << "s" << endl << endl;

    //for (int i = 1000; i <= 30000; i += 1000) {
    //    vector <int> vec(i);
    //    vec = create_vec(i);
    //    auto start = chrono::high_resolution_clock::now();
    //    fibMonaccianSearch(vec, x, i);
    //    /*cout << " Index " << fibMonaccianSearch(vec, x, vec.size()) << "  ";*/
    //    auto end = chrono::high_resolution_clock::now();
    //    chrono::duration<float> duration = end - start;
    //    cout << i << " - " << duration.count() << "s"<<endl;
    //    /*cout<< duration.count()<<"; ";*/
    //}
    return 0;
}





//cout << endl;
//for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
//cout << *it << " ";
//cout << endl;