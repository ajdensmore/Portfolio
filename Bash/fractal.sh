# A bash script to create a fractal tree in 2 iterations

draw () {
    if [[ $2 == 0 ]]; then
        printf "%0.s_" {1..100}
        printf "\n"
        return
    fi
    if (( $1 <= $3 )); then
        tot=$#
        ctr=0
        while (( $ctr < $2 )); do
            curidx=4
            for i in {1..100}; do
                if (( $curidx <= $tot )); then
                    if (( ${!curidx} == $i )); then
                        printf "1"
                        let "curidx++"
                    else
                        printf "_"
                    fi
                else
                    printf "_"
                fi
            done
            printf "\n"
            let "ctr++"
        done
        ctr=0
        arr=()
        while (( $ctr < $2 )); do
            curidx=4
            for i in {1..100}; do
                if (( $curidx <= $tot )); then
                    tar1=$(($i+$ctr+1))
                    tar2=$(($i-$ctr-1))
                    if (( ${!curidx} == $tar1 )); then
                        printf "1"
                        if (( $ctr == $2 - 1 )); then
                            arr+=($i)
                        fi
                    elif (( ${!curidx} == $tar2 )); then
                        printf "1"
                        let "curidx++"
                        if (( $ctr == $2 - 1 )); then
                            arr+=($i)
                        fi
                    else
                        printf "_"
                    fi
                else
                    printf "_"
                fi
            done
            printf "\n"
            let "ctr++"
        done
    else
        ctr=0
        while (( $ctr < $2 )); do
            printf "%0.s_" {1..100}
            printf "\n"
            printf "%0.s_" {1..100}
            printf "\n"
            let "ctr++"
        done
    fi
    draw $(($1+1)) $(($2/2)) $3 ${arr[@]}
}
read line
draw 1 16 $line 50 | tac

