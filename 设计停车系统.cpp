/*
�����һ��ͣ�������һ��ͣ��ϵͳ��ͣ�����ܹ������ֲ�ͬ��С�ĳ�λ�����к�С��ÿ�ֳߴ�ֱ��й̶���Ŀ�ĳ�λ��
����ʵ�� ParkingSystem �ࣺ
ParkingSystem(int big, int medium, int small) ��ʼ�� ParkingSystem �࣬���������ֱ��Ӧÿ��ͣ��λ����Ŀ��
bool addCar(int carType) ����Ƿ��� carType ��Ӧ��ͣ��λ�� carType ���������ͣ����У�С���ֱ������� 1�� 2 �� 3 ��ʾ��һ����ֻ��ͣ��  carType ��Ӧ�ߴ��ͣ��λ�С����û�пճ�λ���뷵�� false �����򽫸ó�ͣ�복λ������ true ��
ʾ�� 1��
���룺
["ParkingSystem", "addCar", "addCar", "addCar", "addCar"]
[[1, 1, 0], [1], [2], [3], [1]]
�����
[null, true, true, false, false]
���ͣ�
ParkingSystem parkingSystem = new ParkingSystem(1, 1, 0);
parkingSystem.addCar(1); // ���� true ����Ϊ�� 1 ���յĴ�λ
parkingSystem.addCar(2); // ���� true ����Ϊ�� 1 ���յ��г�λ
parkingSystem.addCar(3); // ���� false ����Ϊû�пյ�С��λ
parkingSystem.addCar(1); // ���� false ����Ϊû�пյĴ�λ��Ψһһ����λ�Ѿ���ռ����
��ʾ��
0 <= big, medium, small <= 1000
carType ȡֵΪ 1�� 2 �� 3
������� addCar ���� 1000 ��
*/

class ParkingSystem {
    int a[3];
public:
    ParkingSystem(int big, int medium, int small) {
        a[0] = big;
        a[1] = medium;
        a[2] = small;
    }
    
    bool addCar(int carType) {
        return a[carType - 1]-- > 0;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
