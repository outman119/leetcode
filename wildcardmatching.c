bool isMatch(char* s, char* p) {
    if (s == NULL && p == NULL)
        {
            return true;
        }
        if (s== NULL || p==NULL)
        {
            return false;
        }
        if (*p == '\0')
        {
            return *s == '\0';
        }
        char *bs = NULL, *bp = NULL;
        while (*s) 
        {
            if (*p == '?' || *s == *p) 
            {
                ++s;
                ++p;
                continue;
            }
            
            if (*p == '*')
            {
                bs = s;
                bp = p;
                p++;
                continue;
            }
            if (bp)
            {
                p = bp + 1;
                s = bs + 1;
                bs = s;
                continue;
            }
            return false;
        }
        while (*p == '*')
            ++p;
        return (*p == '\0');
}
