    result = 0
    if(p == s):
        return 1
    elif(p > s):
        return 0
    while s>0:
        s = s - p
        p = p - d
        if(p<=m):
            p = m
        result = result + 1
    return result-1