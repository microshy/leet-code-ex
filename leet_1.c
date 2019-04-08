/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct Node{
    struct Node *next;
    int key;
    int value;
}Node;     //定义Node结点
typedef struct hashmap{
    Node* a[11];
}hashmap;     //hash表
int* twoSum(int* nums, int numsSize, int target) {
    hashmap map;
    int index, remain;
    Node *temp;
    int* result;
    //建立返回变量
    result = malloc(sizeof(int)*2);
    //初始化Map指针
    for(int i=0;i<11;i++){
        map.a[i] = malloc(sizeof(Node));
        map.a[i]->next = NULL;    
    }
    //目标数组入表
    for(int i=0;i<numsSize;i++){
        index = (nums[i]>=0?nums[i]:-nums[i])%11;     //取余运算取得表中的索引
        //解决可能存在的冲突
        temp = malloc(sizeof(Node));
        temp->key = nums[i];
        temp->value = i;
        temp->next = map.a[index]->next;                     //使用头插进行插入
        map.a[index]->next = temp;
        remain = target - nums[i];
        //查询取出索引
        index = (remain>=0?remain:-remain)%11;
        temp = map.a[index]->next;
        while(temp){
            if(temp->key == remain && temp->value!= i){        //避免取同一值
                result[0] = i;
                result[1] = temp->value;
                return result;
            }
            temp = temp->next;
        }
    }

    //查询失败
    result[0] = -1;
    result[1] = -1;
    return result;
}