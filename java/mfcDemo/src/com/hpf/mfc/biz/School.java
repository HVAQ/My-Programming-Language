package com.hpf.mfc.biz;

import com.hpf.mfc.link.Link;

public class School extends Link {
    private String city;

    public School(String name) {
        super(name);
    }

    public School(String name, String city) {
        super(name);
        this.city = city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getCity() {
        return this.city;
    }
}
