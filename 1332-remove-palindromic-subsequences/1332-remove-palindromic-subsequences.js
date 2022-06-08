function removePalindromeSub(s){
    if(s == [...s].reverse().join('')){
        return 1;
    }else if(s.includes('a') && s.includes('b')){
        return 2;
    }
    return 1;
};
