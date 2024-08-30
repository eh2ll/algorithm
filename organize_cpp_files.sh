#!/bin/bash

# 파일 패턴에 맞는 모든 .cpp 파일에 대해 반복
for file in bj*.cpp; do
    # 파일명에서 숫자 부분을 추출
    num=$(echo "$file" | sed 's/[^0-9]*//g')
    
    # 추출된 숫자가 비어있지 않은지 확인
    if [ -n "$num" ]; then
        # 숫자를 100으로 나눈 나머지 계산
        remainder=$((num % 100))
        
        # 나머지에 따른 폴더 이름 결정
        if [ "$remainder" -ge 0 ] && [ "$remainder" -lt 10 ]; then
            folder="0-9"
        elif [ "$remainder" -ge 10 ] && [ "$remainder" -lt 20 ]; then
            folder="10-19"
        elif [ "$remainder" -ge 20 ] && [ "$remainder" -lt 30 ]; then
            folder="20-29"
        elif [ "$remainder" -ge 30 ] && [ "$remainder" -lt 40 ]; then
            folder="30-39"
        elif [ "$remainder" -ge 40 ] && [ "$remainder" -lt 50 ]; then
            folder="40-49"
        elif [ "$remainder" -ge 50 ] && [ "$remainder" -lt 60 ]; then
            folder="50-59"
        elif [ "$remainder" -ge 60 ] && [ "$remainder" -lt 70 ]; then
            folder="60-69"
        elif [ "$remainder" -ge 70 ] && [ "$remainder" -lt 80 ]; then
            folder="70-79"
        elif [ "$remainder" -ge 80 ] && [ "$remainder" -lt 90 ]; then
            folder="80-89"
        else
            folder="90-99"
        fi
        
        # 폴더가 존재하지 않으면 생성
        mkdir -p "$folder"
        
        # 파일을 해당 폴더로 이동
        mv "$file" "$folder/"
    else
        echo "파일에서 숫자를 추출할 수 없습니다: $file"
    fi
done
