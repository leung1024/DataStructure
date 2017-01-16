

Status Pass(PosType p) {
    if (Map[p.row][p.col] == 1) // 已经走过的地方会被标1
        return FALSE;
    else
        return TRUE;
}

Status FootPrint(PosType p) {
    Map[p.row][p.col] = 1;
    return OK;
}

PosType NextPos(PosType curpos, int di) {
    PosType nextpos; 
    switch(di) {
        case 1: { // 东
            nextpos.row = curpos.row;
            nextpos.col = curpos.col + 1; 
            break;
        }
        case 2: { // 南
            nextpos.row = curpos.row + 1;
            nextpos.col = curpos.col; 
            break;
        }
        case 3: { // 西
            nextpos.row = curpos.row;
            nextpos.col = curpos.col - 1; 
            break;
        }
        case 4: { // 北
            nextpos.row = curpos.row - 1;
            nextpos.col = curpos.col; 
            break;
        }
    } // switch
    return nextpos;
}

Status MazePath(MazeType maze, PosType start, PosType end) {
    PosType curpos;
    int curstep;
    SElemType e;
    InitStack(s);
    curpos = start;
    curstep = 1;
    do {
        if (Pass(curpos)) { // 当前位置是否被走过
            FootPrint(curpos);
            e = (curstep, curpos, 1);
            Push(s, e);
            if(curpos == end) 
                return TRUE; // 到达终点
            curpos = NextPos(curpos, 1);
            curstep++;
        } // if
        else {
            if (!StackEmpty(s)) {
                Pop(s, e);
                while (e.di == 4 && !StackEmpty(s)) { // 如果四个方向都检查过了则退后一步
                    pop(s, e);
                }
                if (e.di < 4) {
                    e.di++;
                    Push(s, e);
                    curpos = NextPos(e.seat, e.di);
                }
            }
        }
    } while (!StackEmpty(s));

    return ERROR;
    
}
