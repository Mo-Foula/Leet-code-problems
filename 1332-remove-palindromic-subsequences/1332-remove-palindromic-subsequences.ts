function removePalindromeSub(s: string): number{
    if(s == [...s].reverse().join('')){
        return 1;
    }else if(s.includes('a') && s.includes('b')){
        return 2;
    }
    return 1;
};
