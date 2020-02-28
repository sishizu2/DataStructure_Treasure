// 文字列のASCIIコードに重率を掛けてハッシュ値生成
unsigned int MakeHash2(char* str, unsigned int hashmax){

    unsigned int n, length, hash, weight;

    length = strlen(str);

    for(n = weight = hash = 0; n < length; n++, weight++){

        // 重率がintの限界に達したら、一巡して元に戻す
        if(weight > 7){
            weight = 0;
        }

        hash += (int)str[n] << (4 * weight);
        // "<< (4 * weight)" は "256^weight"と同じ意味
    }

    return hash % hashmax;
}