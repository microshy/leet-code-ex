char* longestPalindrome(char* s) {
    int len = 0;
    char* p;
    p = s;
    while (*p != '\0')
    {
        len += 1;
        p += 1;
    }
    char st[len];
    int tbl1[len], tbl2[len], max[2];
    int cnt = 0;
    int tbl1_i = 0;
    int tbl2_i = 0;
    p = s;
    while (*s != '\0')
    {
        if (s != p && *(s + 1) != '\0')
        {
            if (*(s - 1) == *(s + 1) )
            {
                tbl1[tbl1_i] = cnt;
                tbl1_i += 1;

            }
            else if (*s == *(s + 1))
            {
                tbl2[tbl2_i] = cnt;
                tbl2_i += 1;
            }
        }
        st[cnt] = *s;
        cnt += 1;
        s += 1;
    }
    max[0] = 1;
    for (int i = 0; i < tbl1_i; i++)
    {
        for (int j = 1; j <= (tbl1[tbl1_i] < len - tbl1[tbl1_i]) ? tbl1[tbl1_i] : len - tbl1[tbl1_i]; j++)
        {
            printf("%d ",j );
            if (st[tbl1[tbl1_i] - j] != st[tbl1[tbl1_i] + j])
            {
                break;
            }
        }
    }
    return NULL;
}
