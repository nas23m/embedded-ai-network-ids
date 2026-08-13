#include <iostream>
#include <cstdint>
#include <cstring>
using namespace std;

extern "C" void score(double * input, double * output);

#define BUFFER_SIZE 100

struct Connection {
    float timeStamp;
    uint32_t sourceIP;
    uint32_t destinationIP;
    uint16_t sourcePort;
    char service[16];
    char flag[8];
    double duration;
    int protocolType;
    double srcBytes;
    double dstBytes;
    int land;
    int wrongFragment;
    int urgent;
};

double errorRate(Connection* group, int groupSize, const char** errorFlags, int numErrorFlags) {
    int errorCount = 0;
    for (int i = 0; i < groupSize; i++) {
        for (int j = 0; j < numErrorFlags; j++) {
            if (strcmp(group[i].flag, errorFlags[j]) == 0) {
                errorCount++;
                break;
            }
        }
    }
    return (groupSize > 0) ? static_cast<double>(errorCount) / groupSize : 0.0;
}

void buildModelInput(const Connection& conn, const double* mediumFeatures, double* modelInput) {
    int protocolTypeInt=0;
    int serviceInt=0;
    int flagInt=0;

    if (conn.protocolType == 0) {
        protocolTypeInt = 0;
    } else if (conn.protocolType == 1) {
        protocolTypeInt = 1;
    } else if (conn.protocolType == 2) {
        protocolTypeInt = 2;
    } else {
        protocolTypeInt = 3;
    }

    if (strcmp(conn.service, "IRC") == 0) {
        serviceInt = 0;
    } else if (strcmp(conn.service, "X11") == 0) {
        serviceInt = 1;
    } else if (strcmp(conn.service, "Z39_50") == 0) {
        serviceInt = 2;
    } else if (strcmp(conn.service, "aol") == 0) {
        serviceInt = 3;
    } else if (strcmp(conn.service, "auth") == 0) {
        serviceInt = 4;
    } else if (strcmp(conn.service, "bgp") == 0) {
        serviceInt = 5;
    } else if (strcmp(conn.service, "courier") == 0) {
        serviceInt = 6;
    } else if (strcmp(conn.service, "csnet_ns") == 0) {
        serviceInt = 7;
    } else if (strcmp(conn.service, "ctf") == 0) {
        serviceInt = 8;
    } else if (strcmp(conn.service, "daytime") == 0) {
        serviceInt = 9;
    } else if (strcmp(conn.service, "discard") == 0) {
        serviceInt = 10;
    } else if (strcmp(conn.service, "domain") == 0) {
        serviceInt = 11;
    } else if (strcmp(conn.service, "domain_u") == 0) {
        serviceInt = 12;
    } else if (strcmp(conn.service, "echo") == 0) {
        serviceInt = 13;
    } else if (strcmp(conn.service, "eco_i") == 0) {
        serviceInt = 14;
    } else if (strcmp(conn.service, "ecr_i") == 0) {
        serviceInt = 15;
    } else if (strcmp(conn.service, "efs") == 0) {
        serviceInt = 16;
    } else if (strcmp(conn.service, "exec") == 0) {
        serviceInt = 17;
    } else if (strcmp(conn.service, "finger") == 0) {
        serviceInt = 18;
    } else if (strcmp(conn.service, "ftp") == 0) {
        serviceInt = 19;
    } else if (strcmp(conn.service, "ftp_data") == 0) {
        serviceInt = 20;
    } else if (strcmp(conn.service, "gopher") == 0) {
        serviceInt = 21;
    } else if (strcmp(conn.service, "harvest") == 0) {
        serviceInt = 22;
    } else if (strcmp(conn.service, "hostnames") == 0) {
        serviceInt = 23;
    } else if (strcmp(conn.service, "http") == 0) {
        serviceInt = 24;
    } else if (strcmp(conn.service, "http_2784") == 0) {
        serviceInt = 25;
    } else if (strcmp(conn.service, "http_443") == 0) {
        serviceInt = 26;
    } else if (strcmp(conn.service, "http_8001") == 0) {
        serviceInt = 27;
    } else if (strcmp(conn.service, "imap4") == 0) {
        serviceInt = 28;
    } else if (strcmp(conn.service, "iso_tsap") == 0) {
        serviceInt = 29;
    } else if (strcmp(conn.service, "klogin") == 0) {
        serviceInt = 30;
    } else if (strcmp(conn.service, "kshell") == 0) {
        serviceInt = 31;
    } else if (strcmp(conn.service, "ldap") == 0) {
        serviceInt = 32;
    } else if (strcmp(conn.service, "link") == 0) {
        serviceInt = 33;
    } else if (strcmp(conn.service, "login") == 0) {
        serviceInt = 34;
    } else if (strcmp(conn.service, "mtp") == 0) {
        serviceInt = 35;
    } else if (strcmp(conn.service, "name") == 0) {
        serviceInt = 36;
    } else if (strcmp(conn.service, "netbios_dgm") == 0) {
        serviceInt = 37;
    } else if (strcmp(conn.service, "netbios_ns") == 0) {
        serviceInt = 38;
    } else if (strcmp(conn.service, "netbios_ssn") == 0) {
        serviceInt = 39;
    } else if (strcmp(conn.service, "netstat") == 0) {
        serviceInt = 40;
    } else if (strcmp(conn.service, "nnsp") == 0) {
        serviceInt = 41;
    } else if (strcmp(conn.service, "nntp") == 0) {
        serviceInt = 42;
    } else if (strcmp(conn.service, "ntp_u") == 0) {
        serviceInt = 43;
    } else if (strcmp(conn.service, "other") == 0) {
        serviceInt = 44;
    } else if (strcmp(conn.service, "pm_dump") == 0) {
        serviceInt = 45;
    } else if (strcmp(conn.service, "pop_2") == 0) {
        serviceInt = 46;
    } else if (strcmp(conn.service, "pop_3") == 0) {
        serviceInt = 47;
    } else if (strcmp(conn.service, "printer") == 0) {
        serviceInt = 48;
    } else if (strcmp(conn.service, "private") == 0) {
        serviceInt = 49;
    } else if (strcmp(conn.service, "red_i") == 0) {
        serviceInt = 50;
    } else if (strcmp(conn.service, "remote_job") == 0) {
        serviceInt = 51;
    } else if (strcmp(conn.service, "rje") == 0) {
        serviceInt = 52;
    } else if (strcmp(conn.service, "shell") == 0) {
        serviceInt = 53;
    } else if (strcmp(conn.service, "smtp") == 0) {
        serviceInt = 54;
    } else if (strcmp(conn.service, "sql_net") == 0) {
        serviceInt = 55;
    } else if (strcmp(conn.service, "ssh") == 0) {
        serviceInt = 56;
    } else if (strcmp(conn.service, "sunrpc") == 0) {
        serviceInt = 57;
    } else if (strcmp(conn.service, "supdup") == 0) {
        serviceInt = 58;
    } else if (strcmp(conn.service, "systat") == 0) {
        serviceInt = 59;
    } else if (strcmp(conn.service, "telnet") == 0) {
        serviceInt = 60;
    } else if (strcmp(conn.service, "tftp_u") == 0) {
        serviceInt = 61;
    } else if (strcmp(conn.service, "tim_i") == 0) {
        serviceInt = 62;
    } else if (strcmp(conn.service, "time") == 0) {
        serviceInt = 63;
    } else if (strcmp(conn.service, "urh_i") == 0) {
        serviceInt = 64;
    } else if (strcmp(conn.service, "urp_i") == 0) {
        serviceInt = 65;
    } else if (strcmp(conn.service, "uucp") == 0) {
        serviceInt = 66;
    } else if (strcmp(conn.service, "uucp_path") == 0) {
        serviceInt = 67;
    } else if (strcmp(conn.service, "vmnet") == 0) {
        serviceInt = 68;
    } else if (strcmp(conn.service, "whois") == 0) {
        serviceInt = 69;
    } else {
        serviceInt = 70;
    }

    if (strcmp(conn.flag, "OTH") == 0) {
        flagInt = 0;
    } else if (strcmp(conn.flag, "REJ") == 0) {
        flagInt = 1;
    } else if (strcmp(conn.flag, "RSTO") == 0) {
        flagInt = 2;
    } else if (strcmp(conn.flag, "RSTOS0") == 0) {
        flagInt = 3;
    } else if (strcmp(conn.flag, "RSTR") == 0) {
        flagInt = 4;
    } else if (strcmp(conn.flag, "S0") == 0) {
        flagInt = 5;
    } else if (strcmp(conn.flag, "S1") == 0) {
        flagInt = 6;
    } else if (strcmp(conn.flag, "S2") == 0) {
        flagInt = 7;
    } else if (strcmp(conn.flag, "S3") == 0) {
        flagInt = 8;
    } else if (strcmp(conn.flag, "SF") == 0) {
        flagInt = 9;
    } else if (strcmp(conn.flag, "SH") == 0) {
        flagInt = 10;
    } else {
        flagInt = 11;
    }


    modelInput[0] = conn.duration;
    modelInput[1] = protocolTypeInt;
    modelInput[2] = serviceInt;
    modelInput[3] = flagInt;
    modelInput[4] = conn.srcBytes;
    modelInput[5] = conn.dstBytes;
    modelInput[6] = conn.land;
    modelInput[7] = conn.wrongFragment;
    modelInput[8] = conn.urgent;



    for (int i = 0; i < 19; i++) {
        modelInput[i + 9] = mediumFeatures[i];
    }
}

class ConnectionBuffer {
    private:
        Connection buffer[BUFFER_SIZE];
        int index;
        int counter;
    public:
        ConnectionBuffer() : index(0), counter(0) {}

        void addConnection(const Connection& conn) {
            buffer[index] = conn;
            index = (index + 1) % BUFFER_SIZE;
            if (counter < BUFFER_SIZE) {
                counter++;
            }
        }
        int getTimeWindow(double currentTimestamp, double windowSeconds, Connection* result){

            double cutoff = currentTimestamp - windowSeconds;
            int count = 0;
            for (int i = 0; i < counter; i++) {
                int idx = (index - 1 - i + BUFFER_SIZE) % BUFFER_SIZE;
                if (buffer[idx].timeStamp >= cutoff) {
                    result[count++] = buffer[idx];
                } else {
                    break; 
                }
            }
            return count;
        }
        int getHostWindow(uint32_t destinationIP, Connection* result) {
            int count = 0;
            for (int i = 0; i < counter; i++) {
                int idx = (index - 1 - i + BUFFER_SIZE) % BUFFER_SIZE;
                if (buffer[idx].destinationIP == destinationIP) {
                    result[count++] = buffer[idx];
                }
            }
            return count;
        }

        void computeFeatures(const Connection& conn, double* features) {
            computeTimeWindowFeatures(conn, features);
            computeHostWindowFeatures(conn, features);
            addConnection(conn);
}



        void computeTimeWindowFeatures(const Connection& conn, double* features) {
    
    Connection timeWindowConnections[BUFFER_SIZE];
    int timeWindowCount = getTimeWindow(conn.timeStamp, 2.0, timeWindowConnections);
    

    Connection countGroup[BUFFER_SIZE];
    Connection srvCountGroup[BUFFER_SIZE];
    Connection diffServGroup[BUFFER_SIZE];
    int diffServGroupIndex = 0;
    
    int count = 0;
    int srv_count = 0;
    const char* errorFlags[] = {"S0", "S1", "S2", "S3"};
    const char* rejectFlags[] = {"REJ"};
    double same_srv_rate = 0.0;
    double diff_srv_rate = 0.0;
    double srv_diff_host_rate = 0.0;


    for (int i =0 ; i< timeWindowCount; i++) {
        if (timeWindowConnections[i].destinationIP == conn.destinationIP) {
            countGroup[count++] = timeWindowConnections[i];
        }
        if (strcmp(timeWindowConnections[i].service, conn.service) == 0) {
                 srvCountGroup[srv_count++] = timeWindowConnections[i];
                  if (timeWindowConnections[i].destinationIP != conn.destinationIP) {
                  diffServGroupIndex++;
            }
            }
        }

    double serror_rate = errorRate(countGroup, count, errorFlags, sizeof(errorFlags) / sizeof(errorFlags[0]));
    double rerror_rate = errorRate(countGroup, count, rejectFlags, sizeof(rejectFlags) / sizeof(rejectFlags[0]));
    double srv_serror_rate = errorRate(srvCountGroup, srv_count, errorFlags, sizeof(errorFlags) / sizeof(errorFlags[0]));
    double srv_rerror_rate = errorRate(srvCountGroup, srv_count, rejectFlags, sizeof(rejectFlags) / sizeof(rejectFlags[0]));
    same_srv_rate = (count > 0) ? static_cast<double>(srv_count) / count : 0.0;
    diff_srv_rate = 1 - same_srv_rate;
    srv_diff_host_rate = (srv_count > 0) ? static_cast<double>(diffServGroupIndex) / srv_count : 0.0;

    
    
    
    
    
    features[0] = count;
    features[1] = srv_count;
    features[2] = serror_rate;
    features[3] = srv_serror_rate;
    features[4] = rerror_rate;
    features[5] = srv_rerror_rate;
    features[6] = same_srv_rate; 
    features[7] = diff_srv_rate;
    features[8] = srv_diff_host_rate;
}

void computeHostWindowFeatures(const Connection& conn, double* features) {
    Connection hostWindowConnections[BUFFER_SIZE];
    int hostWindowCount = getHostWindow(conn.destinationIP, hostWindowConnections);

    Connection dst_host_srv_count_group[BUFFER_SIZE];

    int dst_host_count = hostWindowCount;
    int dst_host_srv_count = 0;
    int sameSrcPortCount = 0;
    int diffHostCount = 0;
    double dst_host_same_srv_rate = 0.0;
    double dst_host_diff_srv_rate = 0.0;
    double dst_host_same_src_port_rate = 0.0;
    double dst_host_srv_diff_host_rate = 0.0;
    double dst_host_serror_rate = 0.0;
    double dst_host_srv_serror_rate = 0.0;
    double dst_host_rerror_rate = 0.0;
    double dst_host_srv_rerror_rate = 0.0;


    const char* errorFlags[] = {"S0", "S1", "S2", "S3"};
    const char* rejectFlags[] = {"REJ"};

    for (int i = 0; i < hostWindowCount; i++) {
        if (strcmp(hostWindowConnections[i].service, conn.service) == 0) {
            dst_host_srv_count_group[dst_host_srv_count++] = hostWindowConnections[i];
        }
    }
    dst_host_same_srv_rate = (dst_host_count > 0) ? static_cast<double>(dst_host_srv_count) / dst_host_count : 0.0;
    dst_host_diff_srv_rate = 1 - dst_host_same_srv_rate;

    for(int i = 0; i < hostWindowCount; i++){
        if(hostWindowConnections[i].sourcePort == conn.sourcePort){
            sameSrcPortCount++;
        }
    }


    dst_host_same_src_port_rate = (dst_host_count > 0) ? static_cast<double>(sameSrcPortCount) / dst_host_count : 0.0;


    for(int i = 0; i < dst_host_srv_count; i++){
        if(dst_host_srv_count_group[i].sourceIP != conn.sourceIP){
            diffHostCount++;
        }
    }

    dst_host_srv_diff_host_rate = (dst_host_srv_count > 0) ? static_cast<double>(diffHostCount) / dst_host_srv_count : 0.0;


    dst_host_serror_rate = errorRate(hostWindowConnections, hostWindowCount, errorFlags, sizeof(errorFlags) / sizeof(errorFlags[0]));
    dst_host_srv_serror_rate = errorRate(dst_host_srv_count_group, dst_host_srv_count, errorFlags, sizeof(errorFlags) / sizeof(errorFlags[0]));
    dst_host_rerror_rate = errorRate(hostWindowConnections, hostWindowCount, rejectFlags, sizeof(rejectFlags) / sizeof(rejectFlags[0]));
    dst_host_srv_rerror_rate = errorRate(dst_host_srv_count_group, dst_host_srv_count, rejectFlags, sizeof(rejectFlags) / sizeof(rejectFlags[0]));

    features[9] = dst_host_count;
    features[10] = dst_host_srv_count;
    features[11] = dst_host_same_srv_rate;
    features[12] = dst_host_diff_srv_rate;
    features[13] = dst_host_same_src_port_rate;
    features[14] = dst_host_srv_diff_host_rate;
    features[15] = dst_host_serror_rate;
    features[16] = dst_host_srv_serror_rate;
    features[17] = dst_host_rerror_rate;
    features[18] = dst_host_srv_rerror_rate;

}

void predict(const Connection& conn , double* modelOutput) {
    double mediumFeatures[19];
    computeFeatures(conn, mediumFeatures);

    double modelInput[28];
    buildModelInput(conn, mediumFeatures, modelInput);

    score(modelInput, modelOutput);

}
};


