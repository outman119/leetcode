bool isMatch(char* s, char* p) {
    if (*p == '\0')
    {
        return *s == '\0';
    }
    if (*(p + 1) == '*')
    {
        while (*p == *s || (*p == '.' && *s != '\0'))
        {
            if (isMatch(s++, p + 2))
            {
                return true;
            }
        }
        return isMatch(s, p + 2);
    }
    else
    {
        if (*p == *s || (*p == '.' && *s != '\0'))
        {
            return isMatch(s + 1, p + 1);
        }
        return false;
    }
}
