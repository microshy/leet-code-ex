int lengthOfLongestSubstring(char* s) {
    int len = 0;
    for (int i = 0; ; i++)
    {
        if (s[i] == '\0')
            break;
        len += 1;
    }
    int maxSize = 1, maxTmp = 1;
    int same = 0;
    int temp_r = 0;
    for (int i = 0; i < len - 1;)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (temp_r)
            {
                j = (temp_r >= len) ? len : temp_r;
                maxTmp = j - i;
                temp_r = 0;
            }
            for (int k = i; k < i + maxTmp; k++)
            {
                if (s[k] == s[j])
                {
                    same = 1;
                    i = k + 1;
                    temp_r = j;
                    break;
                }
            }
            if (same) break;
            else
                maxTmp += 1;
        }
        if (maxSize >= maxTmp) maxSize = maxSize;
        else maxSize = maxTmp;
        if (same) same = 0;
        else break;
        maxTmp = 1;
    }
    if (len == 0)
        maxSize = 0;
    return maxSize;
}