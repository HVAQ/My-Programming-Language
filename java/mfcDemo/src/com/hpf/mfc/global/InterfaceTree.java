package com.hpf.mfc.global;

public interface InterfaceTree {
    boolean Add(InterfaceTree member);
    boolean Del(InterfaceTree member);
    boolean Change(InterfaceTree member, InterfaceTree newMember);
    InterfaceTree Find(InterfaceTree member);
}
