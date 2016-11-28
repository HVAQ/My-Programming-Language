package com.hpf.mfc.global;

public interface InterfaceLink {
    boolean Add(InterfaceLink member);
    boolean Del(InterfaceLink member);
    boolean Del(int id);
    boolean Change(InterfaceLink member, InterfaceLink newMember);
    boolean Change(int id, InterfaceLink newMember);
    int Find(InterfaceLink member);
    InterfaceLink Find(int id);
}
