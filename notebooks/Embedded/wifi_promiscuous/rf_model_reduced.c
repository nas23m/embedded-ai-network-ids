#include <string.h>
void add_vectors(double *v1, double *v2, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] + v2[i];
}
void mul_vector_number(double *v1, double num, int size, double *result) {
    for(int i = 0; i < size; ++i)
        result[i] = v1[i] * num;
}
void score(double * input, double * output) {
    double var0[2];
    double var1[2];
    double var2[2];
    double var3[2];
    double var4[2];
    double var5[2];
    double var6[2];
    double var7[2];
    double var8[2];
    double var9[2];
    double var10[2];
    if (input[16] <= 0.03499999921768904) {
        if (input[4] <= 28.5) {
            if (input[19] <= 228.5) {
                if (input[5] <= 3.5) {
                    if (input[1] <= 0.5) {
                        memcpy(var10, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.2802265074992348, 0.7197734925007653}, 2 * sizeof(double));
                    }
                } else {
                    if (input[22] <= 0.14499999955296516) {
                        memcpy(var10, (double[]){0.964573268921095, 0.03542673107890499}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.39490445859872614, 0.6050955414012739}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 8.0) {
                    memcpy(var10, (double[]){1.0, 0.0}, 2 * sizeof(double));
                } else {
                    if (input[5] <= 8.5) {
                        memcpy(var10, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[9] <= 324.5) {
                if (input[27] <= 0.014999999664723873) {
                    if (input[22] <= 0.9950000047683716) {
                        memcpy(var10, (double[]){0.9733278235879712, 0.026672176412028775}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.5629183400267738, 0.43708165997322623}, 2 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 15434.5) {
                        memcpy(var10, (double[]){0.960880195599022, 0.039119804400977995}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.022900763358778626, 0.9770992366412213}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[21] <= 0.004999999888241291) {
                    if (input[2] <= 29.5) {
                        memcpy(var10, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 0.5) {
                        memcpy(var10, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[4] <= 28.5) {
            if (input[20] <= 0.8149999976158142) {
                if (input[4] <= 6.5) {
                    if (input[4] <= 5.5) {
                        memcpy(var10, (double[]){0.000561458961508869, 0.9994385410384912}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.08433734939759036, 0.9156626506024096}, 2 * sizeof(double));
                    }
                } else {
                    if (input[26] <= 0.04999999888241291) {
                        memcpy(var10, (double[]){0.9292929292929293, 0.0707070707070707}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 13.0) {
                    memcpy(var10, (double[]){1.0, 0.0}, 2 * sizeof(double));
                } else {
                    if (input[23] <= 0.06999999843537807) {
                        memcpy(var10, (double[]){0.26666666666666666, 0.7333333333333333}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[21] <= 0.004999999888241291) {
                if (input[9] <= 2.5) {
                    memcpy(var10, (double[]){1.0, 0.0}, 2 * sizeof(double));
                } else {
                    if (input[26] <= 0.009999999776482582) {
                        memcpy(var10, (double[]){0.7692307692307693, 0.23076923076923078}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[13] <= 0.08500000089406967) {
                    if (input[26] <= 0.3050000071525574) {
                        memcpy(var10, (double[]){0.9967579250720461, 0.0032420749279538905}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.6, 0.4}, 2 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 3.5) {
                        memcpy(var10, (double[]){0.972972972972973, 0.02702702702702703}, 2 * sizeof(double));
                    } else {
                        memcpy(var10, (double[]){0.4117647058823529, 0.5882352941176471}, 2 * sizeof(double));
                    }
                }
            }
        }
    }
    double var11[2];
    if (input[16] <= 0.03499999921768904) {
        if (input[1] <= 0.5) {
            if (input[10] <= 2.5) {
                if (input[9] <= 1.5) {
                    if (input[18] <= 4.5) {
                        memcpy(var11, (double[]){0.024081115335868188, 0.9759188846641318}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.848404255319149, 0.15159574468085107}, 2 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 14.5) {
                        memcpy(var11, (double[]){0.8591549295774648, 0.14084507042253522}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.7685185185185185, 0.23148148148148148}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[23] <= 0.009999999776482582) {
                    if (input[7] <= 0.5) {
                        memcpy(var11, (double[]){0.017471736896197326, 0.9825282631038027}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var11, (double[]){0.0, 1.0}, 2 * sizeof(double));
                }
            }
        } else {
            if (input[19] <= 2.5) {
                if (input[5] <= 16.0) {
                    if (input[21] <= 0.11499999836087227) {
                        memcpy(var11, (double[]){0.4749034749034749, 0.525096525096525}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.06158264199106573, 0.9384173580089342}, 2 * sizeof(double));
                    }
                } else {
                    if (input[26] <= 0.8849999904632568) {
                        memcpy(var11, (double[]){0.9571843251088534, 0.04281567489114659}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 2.0) {
                    if (input[3] <= 2.5) {
                        memcpy(var11, (double[]){0.9938247780779622, 0.0061752219220378235}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.6844583987441131, 0.315541601255887}, 2 * sizeof(double));
                    }
                } else {
                    if (input[21] <= 0.9749999940395355) {
                        memcpy(var11, (double[]){0.971609445393817, 0.028390554606183005}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.41379310344827586, 0.5862068965517241}, 2 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[5] <= 33.0) {
            if (input[4] <= 28.5) {
                if (input[19] <= 249.5) {
                    if (input[2] <= 1.5) {
                        memcpy(var11, (double[]){0.6875, 0.3125}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.0007238284319808083, 0.9992761715680192}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var11, (double[]){1.0, 0.0}, 2 * sizeof(double));
                }
            } else {
                if (input[27] <= 0.16500000655651093) {
                    if (input[4] <= 3663021.5) {
                        memcpy(var11, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var11, (double[]){0.0, 1.0}, 2 * sizeof(double));
                }
            }
        } else {
            if (input[2] <= 55.0) {
                if (input[24] <= 0.024999999441206455) {
                    if (input[13] <= 0.7450000047683716) {
                        memcpy(var11, (double[]){0.9747368421052631, 0.02526315789473684}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.16666666666666666, 0.8333333333333334}, 2 * sizeof(double));
                    }
                } else {
                    if (input[19] <= 7.5) {
                        memcpy(var11, (double[]){0.09090909090909091, 0.9090909090909091}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){0.8571428571428571, 0.14285714285714285}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[20] <= 0.16500000655651093) {
                    if (input[15] <= 0.375) {
                        memcpy(var11, (double[]){0.5294117647058824, 0.47058823529411764}, 2 * sizeof(double));
                    } else {
                        memcpy(var11, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var11, (double[]){0.0, 1.0}, 2 * sizeof(double));
                }
            }
        }
    }
    add_vectors(var10, var11, 2, var9);
    double var12[2];
    if (input[4] <= 28.5) {
        if (input[21] <= 0.03499999921768904) {
            if (input[13] <= 0.06000000052154064) {
                if (input[10] <= 4.5) {
                    if (input[5] <= 2.0) {
                        memcpy(var12, (double[]){0.25326215895610915, 0.7467378410438908}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.9051546391752577, 0.09484536082474226}, 2 * sizeof(double));
                    }
                } else {
                    if (input[27] <= 0.004999999888241291) {
                        memcpy(var12, (double[]){0.02056877123949204, 0.9794312287605079}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[25] <= 0.3200000002980232) {
                    if (input[26] <= 0.014999999664723873) {
                        memcpy(var12, (double[]){0.8805970149253731, 0.11940298507462686}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.987012987012987, 0.012987012987012988}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var12, (double[]){0.0, 1.0}, 2 * sizeof(double));
                }
            }
        } else {
            if (input[5] <= 33.0) {
                if (input[3] <= 5.5) {
                    if (input[20] <= 0.3400000035762787) {
                        memcpy(var12, (double[]){0.0014289856273039805, 0.998571014372696}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.2988929889298893, 0.7011070110701108}, 2 * sizeof(double));
                    }
                } else {
                    if (input[23] <= 0.004999999888241291) {
                        memcpy(var12, (double[]){0.04867634500426986, 0.9513236549957301}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.8448275862068966, 0.15517241379310345}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[2] <= 18.5) {
                    if (input[9] <= 3.5) {
                        memcpy(var12, (double[]){0.9847560975609756, 0.01524390243902439}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.38461538461538464, 0.6153846153846154}, 2 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 0.08500000089406967) {
                        memcpy(var12, (double[]){0.17525773195876287, 0.8247422680412371}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[4] <= 519.5) {
            if (input[9] <= 2.5) {
                if (input[4] <= 333.5) {
                    if (input[25] <= 0.014999999664723873) {
                        memcpy(var12, (double[]){0.9750806451612903, 0.024919354838709676}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.8533653846153846, 0.1466346153846154}, 2 * sizeof(double));
                    }
                } else {
                    if (input[10] <= 2.5) {
                        memcpy(var12, (double[]){0.6022146507666098, 0.3977853492333901}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.9886792452830189, 0.011320754716981131}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[21] <= 0.9399999976158142) {
                    if (input[12] <= 0.7700000107288361) {
                        memcpy(var12, (double[]){0.9993646025878004, 0.0006353974121996303}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[26] <= 0.4300000071525574) {
                        memcpy(var12, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[9] <= 24.5) {
                if (input[2] <= 36.0) {
                    if (input[20] <= 0.9799999892711639) {
                        memcpy(var12, (double[]){0.8633017875920084, 0.1366982124079916}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.13767629281396912, 0.8623237071860309}, 2 * sizeof(double));
                    }
                } else {
                    if (input[22] <= 0.925000011920929) {
                        memcpy(var12, (double[]){0.9946298984034833, 0.005370101596516691}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.6857142857142857, 0.3142857142857143}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[4] <= 1053.0) {
                    if (input[2] <= 17.5) {
                        memcpy(var12, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[22] <= 0.13500000163912773) {
                        memcpy(var12, (double[]){0.9393939393939394, 0.06060606060606061}, 2 * sizeof(double));
                    } else {
                        memcpy(var12, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var9, var12, 2, var8);
    double var13[2];
    if (input[12] <= 0.574999988079071) {
        if (input[27] <= 0.9950000047683716) {
            if (input[18] <= 4.5) {
                if (input[1] <= 0.5) {
                    if (input[22] <= 0.2900000065565109) {
                        memcpy(var13, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.0037379067722075636, 0.9962620932277925}, 2 * sizeof(double));
                    }
                } else {
                    if (input[19] <= 63.5) {
                        memcpy(var13, (double[]){0.5745992601726264, 0.4254007398273736}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.9969147705360586, 0.0030852294639413806}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[19] <= 211.5) {
                    if (input[9] <= 23.5) {
                        memcpy(var13, (double[]){0.86020540879939, 0.13979459120060994}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.28366823428815735, 0.7163317657118426}, 2 * sizeof(double));
                    }
                } else {
                    if (input[1] <= 0.5) {
                        memcpy(var13, (double[]){0.06794564348521183, 0.9320543565147882}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.9905100830367735, 0.009489916963226572}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[22] <= 0.004999999888241291) {
                if (input[5] <= 7.5) {
                    if (input[21] <= 0.03499999921768904) {
                        memcpy(var13, (double[]){0.9811320754716981, 0.018867924528301886}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.00010955302366345311, 0.9998904469763366}, 2 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 3.5) {
                        memcpy(var13, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.125, 0.875}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[21] <= 0.03499999921768904) {
                    if (input[24] <= 0.004999999888241291) {
                        memcpy(var13, (double[]){0.9843096234309623, 0.015690376569037656}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.14285714285714285, 0.8571428571428571}, 2 * sizeof(double));
                    }
                } else {
                    if (input[20] <= 0.2150000035762787) {
                        memcpy(var13, (double[]){0.006896551724137931, 0.993103448275862}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.6397058823529411, 0.3602941176470588}, 2 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[21] <= 0.004999999888241291) {
            if (input[22] <= 0.044999999925494194) {
                memcpy(var13, (double[]){1.0, 0.0}, 2 * sizeof(double));
            } else {
                if (input[26] <= 0.02500000037252903) {
                    if (input[25] <= 0.14999999850988388) {
                        memcpy(var13, (double[]){0.9807692307692307, 0.019230769230769232}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.14754098360655737, 0.8524590163934426}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var13, (double[]){1.0, 0.0}, 2 * sizeof(double));
                }
            }
        } else {
            if (input[25] <= 0.33500000834465027) {
                if (input[15] <= 0.4950000047683716) {
                    memcpy(var13, (double[]){0.0, 1.0}, 2 * sizeof(double));
                } else {
                    if (input[10] <= 1.5) {
                        memcpy(var13, (double[]){0.9615384615384616, 0.038461538461538464}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.2826086956521739, 0.717391304347826}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[4] <= 48.0) {
                    if (input[15] <= 0.9749999940395355) {
                        memcpy(var13, (double[]){0.0000816171069456158, 0.9999183828930543}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.030211480362537766, 0.9697885196374623}, 2 * sizeof(double));
                    }
                } else {
                    if (input[27] <= 0.1850000061094761) {
                        memcpy(var13, (double[]){0.975609756097561, 0.024390243902439025}, 2 * sizeof(double));
                    } else {
                        memcpy(var13, (double[]){0.8, 0.2}, 2 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var8, var13, 2, var7);
    double var14[2];
    if (input[5] <= 2.5) {
        if (input[22] <= 0.004999999888241291) {
            if (input[16] <= 0.019999999552965164) {
                if (input[3] <= 3.0) {
                    if (input[26] <= 0.9399999976158142) {
                        memcpy(var14, (double[]){0.9814814814814815, 0.018518518518518517}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 0.16500000655651093) {
                        memcpy(var14, (double[]){0.1444866920152091, 0.8555133079847909}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[19] <= 1.5) {
                    if (input[1] <= 0.5) {
                        memcpy(var14, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.0006648936170212766, 0.9993351063829787}, 2 * sizeof(double));
                    }
                } else {
                    if (input[16] <= 0.48000000417232513) {
                        memcpy(var14, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.004545454545454545, 0.9954545454545455}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[10] <= 7.5) {
                if (input[27] <= 0.9950000047683716) {
                    if (input[24] <= 0.8650000095367432) {
                        memcpy(var14, (double[]){0.6695014928073826, 0.33049850719261736}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.0625, 0.9375}, 2 * sizeof(double));
                    }
                } else {
                    if (input[19] <= 7.5) {
                        memcpy(var14, (double[]){0.014480162177816391, 0.9855198378221836}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.9979959919839679, 0.002004008016032064}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[10] <= 24.5) {
                    if (input[9] <= 24.5) {
                        memcpy(var14, (double[]){0.4134443783462225, 0.5865556216537775}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.01164294954721863, 0.9883570504527813}, 2 * sizeof(double));
                    }
                } else {
                    if (input[14] <= 0.044999999925494194) {
                        memcpy(var14, (double[]){0.005387556482446994, 0.994612443517553}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[5] <= 8312.5) {
            if (input[14] <= 0.3150000125169754) {
                if (input[13] <= 0.1550000011920929) {
                    if (input[19] <= 140.5) {
                        memcpy(var14, (double[]){0.9446236559139785, 0.0553763440860215}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.9997897834769813, 0.00021021652301870928}, 2 * sizeof(double));
                    }
                } else {
                    if (input[13] <= 0.6850000023841858) {
                        memcpy(var14, (double[]){0.5866666666666667, 0.41333333333333333}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.03571428571428571, 0.9642857142857143}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[4] <= 17117.0) {
                    if (input[20] <= 0.9950000047683716) {
                        memcpy(var14, (double[]){0.8402061855670103, 0.15979381443298968}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.275, 0.725}, 2 * sizeof(double));
                    }
                } else {
                    if (input[17] <= 0.8350000083446503) {
                        memcpy(var14, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[5] <= 8316.0) {
                if (input[10] <= 2.5) {
                    if (input[27] <= 0.004999999888241291) {
                        memcpy(var14, (double[]){0.029411764705882353, 0.9705882352941176}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var14, (double[]){0.0, 1.0}, 2 * sizeof(double));
                }
            } else {
                if (input[4] <= 104.0) {
                    if (input[11] <= 0.019999999552965164) {
                        memcpy(var14, (double[]){0.30303030303030304, 0.696969696969697}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[26] <= 0.9199999868869781) {
                        memcpy(var14, (double[]){0.9978249048395867, 0.002175095160413268}, 2 * sizeof(double));
                    } else {
                        memcpy(var14, (double[]){0.8888888888888888, 0.1111111111111111}, 2 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var7, var14, 2, var6);
    double var15[2];
    if (input[16] <= 0.03499999921768904) {
        if (input[5] <= 0.5) {
            if (input[19] <= 2.5) {
                if (input[26] <= 0.014999999664723873) {
                    if (input[11] <= 0.25) {
                        memcpy(var15, (double[]){0.6890951276102089, 0.3109048723897912}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.07801418439716312, 0.9219858156028369}, 2 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 31.5) {
                        memcpy(var15, (double[]){0.0043875685557586835, 0.9956124314442413}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.5652173913043478, 0.43478260869565216}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[3] <= 2.5) {
                    if (input[3] <= 0.5) {
                        memcpy(var15, (double[]){0.6666666666666666, 0.3333333333333333}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.9930394431554525, 0.0069605568445475635}, 2 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 16.5) {
                        memcpy(var15, (double[]){0.1043803547725353, 0.8956196452274647}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.6601567689650591, 0.3398432310349409}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[4] <= 20770.5) {
                if (input[3] <= 3.0) {
                    if (input[26] <= 0.6100000143051147) {
                        memcpy(var15, (double[]){0.9838709677419355, 0.016129032258064516}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.07, 0.93}, 2 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 1.5) {
                        memcpy(var15, (double[]){0.9690762521474825, 0.03092374785251751}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.9987717670178503, 0.0012282329821496807}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[4] <= 54704.0) {
                    if (input[25] <= 0.07499999832361937) {
                        memcpy(var15, (double[]){0.006896551724137931, 0.993103448275862}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var15, (double[]){1.0, 0.0}, 2 * sizeof(double));
                }
            }
        }
    } else {
        if (input[1] <= 0.5) {
            if (input[22] <= 0.8799999952316284) {
                if (input[10] <= 1.5) {
                    if (input[15] <= 0.024999999441206455) {
                        memcpy(var15, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var15, (double[]){1.0, 0.0}, 2 * sizeof(double));
                }
            } else {
                memcpy(var15, (double[]){0.0, 1.0}, 2 * sizeof(double));
            }
        } else {
            if (input[19] <= 77.5) {
                if (input[5] <= 31.5) {
                    if (input[3] <= 5.5) {
                        memcpy(var15, (double[]){0.0002571024553284484, 0.9997428975446716}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.35612835349815886, 0.6438716465018411}, 2 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 11.5) {
                        memcpy(var15, (double[]){0.8015665796344648, 0.19843342036553524}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.9962894248608535, 0.0037105751391465678}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[21] <= 0.044999999925494194) {
                    if (input[24] <= 0.8549999892711639) {
                        memcpy(var15, (double[]){0.9917763157894737, 0.008223684210526315}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 51.5) {
                        memcpy(var15, (double[]){0.25609756097560976, 0.7439024390243902}, 2 * sizeof(double));
                    } else {
                        memcpy(var15, (double[]){0.9512195121951219, 0.04878048780487805}, 2 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var6, var15, 2, var5);
    double var16[2];
    if (input[15] <= 0.4950000047683716) {
        if (input[3] <= 5.5) {
            if (input[16] <= 0.019999999552965164) {
                if (input[2] <= 36.5) {
                    memcpy(var16, (double[]){1.0, 0.0}, 2 * sizeof(double));
                } else {
                    memcpy(var16, (double[]){0.0, 1.0}, 2 * sizeof(double));
                }
            } else {
                if (input[19] <= 90.0) {
                    if (input[0] <= 3278.0) {
                        memcpy(var16, (double[]){0.00010949304719150334, 0.9998905069528085}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[20] <= 0.5750000029802322) {
                        memcpy(var16, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[21] <= 0.13499999791383743) {
                if (input[22] <= 0.9600000083446503) {
                    if (input[26] <= 0.014999999664723873) {
                        memcpy(var16, (double[]){0.9786535303776683, 0.021346469622331693}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.14130434782608695, 0.8586956521739131}, 2 * sizeof(double));
                    }
                } else {
                    if (input[16] <= 0.39500000700354576) {
                        memcpy(var16, (double[]){0.018867924528301886, 0.9811320754716981}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[4] <= 51.5) {
                    if (input[23] <= 0.009999999776482582) {
                        memcpy(var16, (double[]){0.005252100840336135, 0.9947478991596639}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.6, 0.4}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var16, (double[]){1.0, 0.0}, 2 * sizeof(double));
                }
            }
        }
    } else {
        if (input[19] <= 210.5) {
            if (input[5] <= 2.5) {
                if (input[25] <= 0.8149999976158142) {
                    if (input[22] <= 0.5149999856948853) {
                        memcpy(var16, (double[]){0.61312, 0.38688}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.16533305621947417, 0.8346669437805259}, 2 * sizeof(double));
                    }
                } else {
                    if (input[11] <= 0.25) {
                        memcpy(var16, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.00946643717728055, 0.9905335628227194}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[23] <= 0.004999999888241291) {
                    if (input[21] <= 0.004999999888241291) {
                        memcpy(var16, (double[]){0.47854785478547857, 0.5214521452145214}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.9520927237604636, 0.04790727623953638}, 2 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 61.5) {
                        memcpy(var16, (double[]){0.9890909090909091, 0.01090909090909091}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[17] <= 0.9399999976158142) {
                if (input[4] <= 519.5) {
                    if (input[20] <= 0.375) {
                        memcpy(var16, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.9970712909441233, 0.002928709055876686}, 2 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 161.0) {
                        memcpy(var16, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.4263157894736842, 0.5736842105263158}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[23] <= 0.24499999731779099) {
                    if (input[27] <= 0.004999999888241291) {
                        memcpy(var16, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){0.9614512471655329, 0.03854875283446712}, 2 * sizeof(double));
                    }
                } else {
                    if (input[26] <= 0.46000000834465027) {
                        memcpy(var16, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var16, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var5, var16, 2, var4);
    double var17[2];
    if (input[25] <= 0.8550000190734863) {
        if (input[19] <= 99.5) {
            if (input[4] <= 28.5) {
                if (input[10] <= 2.5) {
                    if (input[26] <= 0.054999999701976776) {
                        memcpy(var17, (double[]){0.6224336504757135, 0.3775663495242864}, 2 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.06371342630571507, 0.9362865736942849}, 2 * sizeof(double));
                    }
                } else {
                    if (input[26] <= 0.054999999701976776) {
                        memcpy(var17, (double[]){0.020458015267175573, 0.9795419847328244}, 2 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.003934871099050203, 0.9960651289009498}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[21] <= 0.004999999888241291) {
                    if (input[5] <= 0.5) {
                        memcpy(var17, (double[]){0.30639097744360905, 0.693609022556391}, 2 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.641860465116279, 0.3581395348837209}, 2 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 4.5) {
                        memcpy(var17, (double[]){0.861013490533953, 0.13898650946604693}, 2 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.9757557617479796, 0.024244238252020354}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[1] <= 0.5) {
                if (input[9] <= 5.0) {
                    if (input[18] <= 6.0) {
                        memcpy(var17, (double[]){0.0021208907741251328, 0.9978791092258749}, 2 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.9623287671232876, 0.03767123287671233}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var17, (double[]){0.0, 1.0}, 2 * sizeof(double));
                }
            } else {
                if (input[27] <= 0.004999999888241291) {
                    if (input[25] <= 0.044999999925494194) {
                        memcpy(var17, (double[]){0.9886130213450032, 0.011386978654996873}, 2 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.5153061224489796, 0.4846938775510204}, 2 * sizeof(double));
                    }
                } else {
                    if (input[10] <= 1.5) {
                        memcpy(var17, (double[]){0.971395881006865, 0.028604118993135013}, 2 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.8282102844010342, 0.1717897155989658}, 2 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[11] <= 0.009999999776482582) {
            if (input[22] <= 0.08499999903142452) {
                memcpy(var17, (double[]){1.0, 0.0}, 2 * sizeof(double));
            } else {
                memcpy(var17, (double[]){0.0, 1.0}, 2 * sizeof(double));
            }
        } else {
            if (input[20] <= 0.949999988079071) {
                if (input[2] <= 0.5) {
                    memcpy(var17, (double[]){1.0, 0.0}, 2 * sizeof(double));
                } else {
                    if (input[9] <= 1.5) {
                        memcpy(var17, (double[]){0.04843304843304843, 0.9515669515669516}, 2 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.00008227969611365568, 0.9999177203038864}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[5] <= 0.5) {
                    if (input[18] <= 1.5) {
                        memcpy(var17, (double[]){0.3333333333333333, 0.6666666666666666}, 2 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 56.5) {
                        memcpy(var17, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var17, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var4, var17, 2, var3);
    double var18[2];
    if (input[3] <= 5.5) {
        if (input[20] <= 0.5949999988079071) {
            if (input[5] <= 196.5) {
                if (input[16] <= 0.019999999552965164) {
                    if (input[20] <= 0.054999999701976776) {
                        memcpy(var18, (double[]){0.016364902506963788, 0.9836350974930362}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.20656370656370657, 0.7934362934362934}, 2 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 5.5) {
                        memcpy(var18, (double[]){0.01818181818181818, 0.9818181818181818}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[20] <= 0.004999999888241291) {
                    if (input[26] <= 0.5) {
                        memcpy(var18, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[19] <= 121.0) {
                        memcpy(var18, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[4] <= 120.0) {
                if (input[11] <= 0.5850000083446503) {
                    if (input[18] <= 1.5) {
                        memcpy(var18, (double[]){0.959349593495935, 0.04065040650406504}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.9980135081446166, 0.001986491855383393}, 2 * sizeof(double));
                    }
                } else {
                    if (input[9] <= 2.5) {
                        memcpy(var18, (double[]){0.6666666666666666, 0.3333333333333333}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.015625, 0.984375}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[0] <= 430.5) {
                    if (input[14] <= 0.1550000011920929) {
                        memcpy(var18, (double[]){0.9, 0.1}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.08860759493670886, 0.9113924050632911}, 2 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 108639727.0) {
                        memcpy(var18, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            }
        }
    } else {
        if (input[4] <= 28.5) {
            if (input[18] <= 4.5) {
                if (input[22] <= 0.75) {
                    if (input[12] <= 0.10000000149011612) {
                        memcpy(var18, (double[]){0.5641025641025641, 0.4358974358974359}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[19] <= 12.5) {
                        memcpy(var18, (double[]){0.0810126582278481, 0.9189873417721519}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.004373177842565598, 0.9956268221574344}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 1.5) {
                    if (input[19] <= 1.5) {
                        memcpy(var18, (double[]){0.08443271767810026, 0.9155672823218998}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.8766617429837519, 0.12333825701624815}, 2 * sizeof(double));
                    }
                } else {
                    if (input[4] <= 11.0) {
                        memcpy(var18, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.041176470588235294, 0.9588235294117647}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[5] <= 0.5) {
                if (input[20] <= 0.5450000166893005) {
                    if (input[9] <= 47.5) {
                        memcpy(var18, (double[]){0.9541568128069856, 0.04584318719301437}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.024526198439241916, 0.9754738015607581}, 2 * sizeof(double));
                    }
                } else {
                    if (input[2] <= 14.5) {
                        memcpy(var18, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.27167630057803466, 0.7283236994219653}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[4] <= 52163.5) {
                    if (input[4] <= 1137.5) {
                        memcpy(var18, (double[]){0.9984077767535406, 0.0015922232464593983}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.9296355718542287, 0.07036442814577126}, 2 * sizeof(double));
                    }
                } else {
                    if (input[0] <= 0.5) {
                        memcpy(var18, (double[]){0.01722158438576349, 0.9827784156142365}, 2 * sizeof(double));
                    } else {
                        memcpy(var18, (double[]){0.6705882352941176, 0.32941176470588235}, 2 * sizeof(double));
                    }
                }
            }
        }
    }
    add_vectors(var3, var18, 2, var2);
    double var19[2];
    if (input[19] <= 69.5) {
        if (input[4] <= 8.5) {
            if (input[5] <= 133.5) {
                if (input[20] <= 0.3449999988079071) {
                    if (input[10] <= 1.5) {
                        memcpy(var19, (double[]){0.018151173343705432, 0.9818488266562946}, 2 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.000803434106925602, 0.9991965658930744}, 2 * sizeof(double));
                    }
                } else {
                    if (input[22] <= 0.6899999976158142) {
                        memcpy(var19, (double[]){0.5672082717872969, 0.4327917282127031}, 2 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.03774680603948897, 0.962253193960511}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[18] <= 19.0) {
                    if (input[25] <= 0.009999999776482582) {
                        memcpy(var19, (double[]){0.2857142857142857, 0.7142857142857143}, 2 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[11] <= 0.009999999776482582) {
                        memcpy(var19, (double[]){0.9700374531835206, 0.0299625468164794}, 2 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                }
            }
        } else {
            if (input[7] <= 0.5) {
                if (input[9] <= 222.0) {
                    if (input[19] <= 8.5) {
                        memcpy(var19, (double[]){0.9429077229475548, 0.05709227705244523}, 2 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.8367398119122257, 0.1632601880877743}, 2 * sizeof(double));
                    }
                } else {
                    if (input[5] <= 290.5) {
                        memcpy(var19, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.8888888888888888, 0.1111111111111111}, 2 * sizeof(double));
                    }
                }
            } else {
                memcpy(var19, (double[]){0.0, 1.0}, 2 * sizeof(double));
            }
        }
    } else {
        if (input[4] <= 28.5) {
            if (input[17] <= 0.9149999916553497) {
                if (input[3] <= 2.5) {
                    if (input[2] <= 22.0) {
                        memcpy(var19, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.9965986394557823, 0.003401360544217687}, 2 * sizeof(double));
                    }
                } else {
                    if (input[22] <= 0.26500000059604645) {
                        memcpy(var19, (double[]){0.6020942408376964, 0.39790575916230364}, 2 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.1541501976284585, 0.8458498023715415}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[13] <= 0.9600000083446503) {
                    if (input[18] <= 5.5) {
                        memcpy(var19, (double[]){0.0013774104683195593, 0.9986225895316805}, 2 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.8387096774193549, 0.16129032258064516}, 2 * sizeof(double));
                    }
                } else {
                    memcpy(var19, (double[]){1.0, 0.0}, 2 * sizeof(double));
                }
            }
        } else {
            if (input[9] <= 323.5) {
                if (input[1] <= 0.5) {
                    if (input[4] <= 350.5) {
                        memcpy(var19, (double[]){1.0, 0.0}, 2 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.0, 1.0}, 2 * sizeof(double));
                    }
                } else {
                    if (input[23] <= 0.004999999888241291) {
                        memcpy(var19, (double[]){0.9558389727572445, 0.04416102724275551}, 2 * sizeof(double));
                    } else {
                        memcpy(var19, (double[]){0.9996547491176921, 0.0003452508823078103}, 2 * sizeof(double));
                    }
                }
            } else {
                if (input[1] <= 1.0) {
                    memcpy(var19, (double[]){0.0, 1.0}, 2 * sizeof(double));
                } else {
                    memcpy(var19, (double[]){1.0, 0.0}, 2 * sizeof(double));
                }
            }
        }
    }
    add_vectors(var2, var19, 2, var1);
    mul_vector_number(var1, 0.1, 2, var0);
    memcpy(output, var0, 2 * sizeof(double));
}
