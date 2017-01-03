package com.sims.dao.util;

import java.io.IOException;
import java.io.InputStream;
import java.util.Properties;

/**
 * 配置文件属性项目获取
 * Created by whoami on 2016/12/30.
 */
public class Config {
    private static final Config config = new Config();
    private Config () {
    }

    public static Config getConfig() {
        return config;
    }

    public String getDBConfig(String key) {
        InputStream input = this.getClass().getClassLoader().getResourceAsStream("DBConfig.properties");
        Properties p = new Properties();
        try {
            p.load(input);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return p.getProperty(key);
    }
}
