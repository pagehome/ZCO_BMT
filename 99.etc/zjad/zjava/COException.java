// Decompiled by Jad v1.5.8g. Copyright 2001 Pavel Kouznetsov.
// Jad home page: http://www.kpdus.com/jad.html
// Decompiler options: packimports(3) 
// Source File Name:   COException.java

package com.cubeone;


public class COException extends Exception
{

    public COException(String s, int i)
    {
        super(s);
        ErrState = s;
        ErrCode = i;
    }

    public String getErrState()
    {
        return ErrState;
    }

    public int getErrCode()
    {
        return ErrCode;
    }

    private String ErrState;
    private int ErrCode;
}
