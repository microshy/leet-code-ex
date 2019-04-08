/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Node{
    struct Node *next;
    int key;
    int value;
}Node;     //����Node���
typedef struct hashmap{
    Node* a[11];
}hashmap;     //hash��
int* twoSum(int* nums, int numsSize, int target) {
    hashmap map;
    int index, remain;
    Node *temp;
    int* result;
    //�������ر���
    result = malloc(sizeof(int)*2);
    //��ʼ��Mapָ��
    for(int i=0;i<11;i++){
        map.a[i] = malloc(sizeof(Node));
        map.a[i]->next = NULL;    
    }
    //Ŀ���������
    for(int i=0;i<numsSize;i++){
        index = (nums[i]>=0?nums[i]:-nums[i])%11;     //ȡ������ȡ�ñ��е�����
        //������ܴ��ڵĳ�ͻ
        temp = malloc(sizeof(Node));
        temp->key = nums[i];
        temp->value = i;
        temp->next = map.a[index]->next;                     //ʹ��ͷ����в���
        map.a[index]->next = temp;
        remain = target - nums[i];
        //��ѯȡ������
        index = (remain>=0?remain:-remain)%11;
        temp = map.a[index]->next;
        while(temp){
            if(temp->key == remain && temp->value!= i){        //����ȡͬһֵ
                result[0] = i;
                result[1] = temp->value;
                return result;
            }
            temp = temp->next;
        }
    }

    //��ѯʧ��
    result[0] = -1;
    result[1] = -1;
    return result;
}