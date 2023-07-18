#ifndef STRC_H
#define STRC_H
#include <QSqlQuery>

#endif // STRC_H

int proses_q( QSqlQuery *q, const char *s, ...);
#define BESAR_PAKET         /*60*/ 400 /*30*/
struct t_rute_xx {
        unsigned short 	flag;				 // 2 sudah di trap atau belum
        unsigned short	point_ke;            // 2 baru ditambahkan
        char 			inisial[10];     	 // 10  //jeneng di viro
        short  			sudut_fasa;     	 // 2
        unsigned char	kanal;				 // 20 Jan 2011, sofhaliza sudah sejak 11 Okt 2010
        unsigned char 	mask;				 // 20 jan 2011
        short		    tipe_data;           // 2
        unsigned short	id_titik;         	 // 2
        unsigned short	id_rute;             // id_mesin ?
        unsigned short 	id_dikirim;			 // 2  ditambahkan 17 juli, supaya satu rute bisa dipakai beberapa kali
};

struct t_rute {
    unsigned short 	flag;				 	// 2  sudah di trap atau belum
    unsigned short	point_ke;         		// 2  baru ditambahkan
    char 			inisial[10];     	  	// 10
    short  			sudut_fasa;     	  	// 2
    unsigned char	kanal;					// 1  20 Jan 2011, sofhaliza sudah sejak 11 Okt 2010
    unsigned char 	mask;					// 1  20 jan 2011
    short			id_tipe_param;    	    // 2  (di haliza ==> tipe_data)
    unsigned short	id_param;         		// 2  (2014, ini menjadi id_n_param), id_aset
    unsigned short	id_rute;				// 2  total = 38 bytes	--> id_rute (yg bener id_rute)
    unsigned short 	id_dikirim;				// 2  ditambahkan 17 juli, supaya satu rute bisa dipakai beberapa kali
};



struct t_kom_dat {						     // struk paket komunikasi
        char 		kpl[10];
        char 		iden[6];
        struct t_rute rute;                 //yg dipake inisial aja
        unsigned short 	data[ BESAR_PAKET ];
        unsigned short	cek[10];
};

struct t_kom_dat_new {						     // struk paket komunikasi
        char 		kpl[10];
        char 		iden[6];
        struct t_rute rute;                 //yg dipake inisial aja
        unsigned short 	data[ /*BESAR_PAKET*/ 30];
        unsigned short	cek[10];
};

struct t_info_rotat {
        float 	peak;				// tertinggi pada domain frekuensi
        float	overall;			// harga overall pada domain waktu (sesuai dengan RMS, PP atau P)
        float	f_maks;				// frekuensi saat peak.

        unsigned short keluaran;
        unsigned short fft_point;  //lengt data // lines parameter
        unsigned short low_cut;     //f_stop
        unsigned short high_pass;   //f_start
        unsigned short averages;
        unsigned short window;
        unsigned short PP;

        /* 16 sept 2009, model integrasi
                1 untuk digital integration
                2 untuk analog integration (IIR filter)
        */
        unsigned short integrasi;

        /* 19 Sept 2009, skala auto / tidak */
        unsigned short skala;

        /* 20 sept 2009, faktor kalibrasi */
        float accel_A;
        float accel_B;

        /* 29 Okt 2009 */
        unsigned short satuan;		// metrik, inggris
        unsigned short sat_frek;	// Hz, CPM, RPM
        unsigned short skala_log;	// log, linear
        unsigned short cursor;		// satu saja atau harmonik
        unsigned short screen;		// spektrum saja, + waveform

        /* 31 Okt 2009 */
        float f_perlines;		// f_perlines sesungguhnya dari sampling rate sesungguhnya

        /* 2 Nov 2009 */
        short cur_avg;
        float faktor_default;		// faktor hanning, hamming dll
        float reff_rpm;

        /* 4 Nov 2009 */
        float mean;
        float mean_asli;			// raw data sebelum dikali faktor kalibrasi
        float f_scaling;			// pengaruh scalling

        /* 22 Mar 2010 */
        int anal_gain;				// setting analog gain pada LTC1564

        /* 21 Juli 2010 */
        float f_MA;					// milivolt maksimum
        float f_MI;

        /* 10 Agt 2010 */
        unsigned long long 	tim;	/* waktu saat data disimpan, NOTE : ini sering problem antar platform
                                untuk ARM/Haliza, WIndows 32/64 dan Linux 32/64
                                pe Sept 2016, diganti ke long long

                                tadinya long
                                */
        unsigned char phase;	// 2 = disable, 1 = enable
        unsigned char kanal;	//  0/1 => 1 kanal, 2 = 2 kanal.

        /* 20 MEI 2013 WARN WARN, mungkin tidak cocok dengan database/sofHaliza */
        int custom_srate;           // sampling rate custom
        int overlap;                // maksimum 100 (100 persen overlap)

        char mode_fase;              // 1 = 360 dan 2 = 720
        char sumber_fase;            // 0 = pickup, 1 = ch1, 2 = ch2
        char band_fase;
        char flag_valid;             // valid strukturnya
        float beda_fase;             // beda fase yang terukur

        char show_kurva_PU;     /* kurva pickup dimunculkan */
        unsigned int 	dummy;
        unsigned int 	dummy2;


#if 1
        /* 18 Mei 2011, tentang batas alarm dan batas fault juga bearing */
        float   alarm;
        float   fault;

        char    bearing_maker[64];
        char    bearing_model[64];
        float   bpfo;
        float   bpfi;
        float   ftf;
        float   bsf;
#endif
        /* 27 Okt 2014, di buat 4 versi Vel, Acc, Disp, Volt */
        //unsigned short keluaran;
};

struct set_param_vibro
{
    unsigned short point_ke; //titik pengukuran ke
    char nama_point[10]; //nama titik pengukuran
    // id from database softhaliza
    int id_isi;
    int id_param;
    int id_tipe_param;
    int id_aset;
    int id_kind;

    int f_start;
    int f_stop;
    int lines; //
    int s_rate; // belum dipakai
    int tipe_data; //41 = accelerometer 42 = velocity

    int satuan; // rung dipakai
    int windowing; //0 = hanning
    float reff_rpm; //properties aset di sofhaliza

    int jenis_mesin; //blm dipakai
    //hasil vibro
    float cress_factor;
    float peak; //peak dalam time domain (waveform)
    float amplitude; //amplitude max - min value (waveform)
    float rms; //peak dalam time domain (rms waveform)
    float frek_maks; // X spektrum
    float peak_frek_maks; // Y spektrum

    // Selasa 19/03/20 14:39:00
    char time_stamp[25]; // waktu ambil data
};

struct t_master_vibro {
    int id_database;
    char nama_pers[64];
    char nama_dept[64];
    char nama_unit[64];
    char nama_rute[64];
    char waktu_kirim[64];
    int epoch_time; //waktu rute send

    //jono 24 feb 2022
//    int machine_class; //machine_class semetara dimasukkan hardcode disini dan disi dengan 1 -- ISO 10816-1
    //tambah isi baru, agar mudah dibaca oleh viro
    int     tipe;               /* pompa, turbin, blower dst */
    int     std_alarm;          /* user defined, ISO10816-1 {0,1} */
    int     cat_alarm;          /* Class I, Class II, Class III, Class IV*/
    float   alarm_lvl[4];       /* good, satisfied, alert, danger */

};

//struct t_statistik_rotat {
//    float overall_rms;
//    float overall_peak;
//    float peak_wf;
//    float rms_wf;
//    float cf;
//    int index_machine_severity;
//    unsigned long long timestamp;
//    int unit_temp; //UNIT_CELCIUS or UNIT_FAHRENHEIT
//    float temp;
//};

//jono baru 24 Feb 2022
struct t_statistik_rotat{
    int reff_rpm;       //reff rpm
    int dec_f;	        // volt
    int point;		// volt
    float vel_ampl;		// mm/s - Peak freq dominan
    float vel_frekDom;		// mm/s - RMS freq dominan
    float vel_overall_peak;     // mm/s overal dari spektrum dlm peak
    float vel_overall_rms;      // mm/s overal dari spektrum dlm rms
//    float rpm;                  // vel freq dominan(hz)*60
    float env_wf_peak;          // g's
    float env_wf_rms;           // g's
    float env_wf_cf;		// ratio (env_peak dibagi env_rms)
    float temp;                 // temp from dual sensor accelerometer-temp
    int unit_temp; 		// UNIT_CELCIUS or UNIT_FAHRENHEIT (1000 , 1100)
    unsigned long long timestamp;   //in epoch time second
};



struct t_rute_vibro {
    // unsigned short 	flag;				 	// 2 sudah di trap atau belum
    unsigned short	point_ke;         		// 2 baru ditambahkan
    char 			jeneng[10];     	  	// 10
    // short  			sudut_fasa;     	  	// 2
    // unsigned char	kanal;					// 20 Jan 2011, sofhaliza sudah sejak 11 Okt 2010
    // unsigned char 	mask;					// 20 jan 2011
    short			tipe_data;    	    	//ACC(41)/VEL(42)/DIS(43)   //2
    // unsigned short	id_titik;         		//2 (2014, ini menjadi id_n_param)
    // unsigned short	id_mesin;				//2	total = 38 bytes	--> id_rute (yg bener id_rute)
    // unsigned short 	id_dikirim;				//2	ditambahkan 17 juli, supaya satu rute bisa dipakai beberapa kali
};


struct t_kom_dat_vibro {                          //struk paket komunikasi
    char            kpl[10];
    char            iden[6];
    struct t_rute_vibro   rute;
    unsigned short 	data[ 400];
    unsigned short	cek[10];
};

/* auxiliary struct untuk ploting2 */
struct t_plot_aux{
        //int  tipe_data;     /* untuk menentukan struct yang dipakai, diganti dengan id_tipe_param */
        int  num_sample;    /* jumlah sample, terutama untuk recip */
        //char *title;
        //char *nama_point;
        char deskripsi[64];
        char date[32];      /* rute send */
        char nama_sub_unit[128]; // rotating
        char nama_unit[128];     // mesin, equipment
        char nama_lokasi[128];   // nama lokasi/group
        char nama_dept[128];
        //char nama_pt[128];       // nama perusahaan
        char info_unit[1024];       // nama perusahaan dll
        char plot_info[128];     // yang diplot di kanvas grafik
        char satuan_bawah[32];
        char satuan_kiri[32];
        char judul_plot[64];

        /* info2 sebelah kanan grafik */
        char info_judul[32];         // judul info sebelah kanan
        char info_overall[32];         // overal value
        char info_peak[32];    // peak
        char info_rpm[32];
        char info_load[32];
        char info_rute[32];
        char info_tgl[32];
        char info_jam[32];

        /* baru Agt 2015 */
        int id_data;        /* dari tabel data sesuai nama tabel */
        int id_aset;
        int id_param;
        int id_tipe_param;
        int id_date;
        char db_con_name[128];
        int flag_4_tak;
        int fft_point;
        int kind;

        char title[256];
        char nama_point[32];
        char paramnya[33];
        int flag_urutan_parade;    /* 0 biasa (parade ditumpuk), 1 parade sesuai firing order */

        /* dibutuhkan guna menyimpan sudut fasa untuk parade */
        double phase_angle;

        int id_siklus[128];
        int num_siklus;
        int index_siklus;

        /* flag apakah plot waveform */
        int flag_wf;

        int flag_pv;
};

struct t_simpan_data_baru {
    int id_param;
    char *dat;          // (blob)
    float info_rms;
    float info_peak;
    int id_date;
    char *setting;      // (blob)
    int id_aset;       //buat data off rute
};


struct t_simpan_data {
        int     id_unit;       /* tadinya id_point */
        int     id_tipe;
        int     periode;
        int     size;
        char    nama_titik[128];        /* kadang berisi nama file yang dimasukkan manual, misalnya gambar, pdf dll */
        int     id_send;
        int     id_rute;                /* tadinya id_unit */
        char    ext[32];                /* ekstension file jika dimasukkan manual */

        int id_param;
        char *dat;          // (blob)
        float info_rms;
        float info_peak;
        int id_date;
        int id_data_masuk;
        char *setting;      // (blob)
};

struct t_image_data {
        char    *image;
        int     size;
};

/*
struct t_blob_recip
{
        struct t_dd_recip dd_recip;

}*/

struct t_setting
{
    /* port komunikasi */
    int  use;               /*17 jan 2018 diganti menjadi (0 serial, 1 bluetooth )//  <> 1 serial, 2 bluetooth, 3 usb, serial */
    char port_name[64];
    char port_speed[32];
    int use_temp;

    /* unutk kumonikasi TCP */
    QString address_Tcp;
    int port_tcp;

    QString con_name;

    /* 17 Jan 2018*/
    int protokol;   /* 0 untuk sofhaliza 8, 1 unutk sofhaliza 10 */

    /* 16 maret 2020 ,  point ke index combobox */
    char vibro_com[64];
    char vibro_speed[32];
    char vibro_protokol_ver[32];
    int mode_komu_device=0;

    /*  database terakhir dibuka
        supaya saat dijalanin lagi langsung buka database terakhir ini */
    char last_open[1024];

    /* satuan */
    int unit_acc;       /* 1 m/s², 2 G */
    int unit_velo;      /* 1 mm/s, 2 IPS */
    int unit_disp;      /* 1 mm, 2 micron, 3 mills, */
    int unit_pcomb;     /* 1 bar, 2 psi */
    int unit_temp;      /* 1 Celecius, 2 Fahrenheit */
    int unit_ihp;       /* 1 kW, 2 horse power */
    int unit_flow_komp; /* 1 MMSCFD, 2 M3/h */
    int unit_frek;      /* 1 Hz, 2 rpm, 3 order */
    int unit_time;      /* 1 milisecond, 2 second, 3 Cycle*/
    int unit_rod_load;   /* 1 newton, 2 LBS */
    int unit_length; /* 1 mm, 2 inch  */

    /* warna grafik qwtplot */
    /* Warna */
    QString curve_color[25];    // warna curve_plot
    QString background_color;   // warna background_plot
    QString grid_color;         // warna grid_plot
    QString body_color;         // warna body_plot
    int     curve_size_index;   // index ukuran curve
    float   curve_size;         // ukuran curve
    bool    check_legend;       // Checkbox Legend
    bool    check_info;         // Checkbox Info curve
    /* Skala */
    QString model_font_scale;   // model huruf_skala
    int size_font_scale;        // ukuran huruf_skala
    /* Judul */
    QString model_font_title;   // model huruf_judul
    int size_font_title;        // ukuran huruf_judul
    QString font_title_color;   // warna huruf_judul

    /* Judul Plot*/
    QString model_font_plot_title;  //model plot_judul
    int size_font_plot_title;       //ukuran plot_judul
    QString font_plot_title_color;  //warna plot_judul

    /* default rotating */
    int high_pass;
    int low_pass;
    int fft_point;
    int averages;
    int window;
    int PP;
    int keluaran;
    int multipeak;
    int sideband;
    /* belum digunakan di form spektrum, sepertinya  t_setting digunakan pada
     * struct pengaturan bukan pada tiap siklus spektrum rotating
    */
    bool set_rpm;
    int new_rpm;

    /* nilai filter */
    int high_filter_val;
    int low_filter_val;

    /* setting buat filter nilai dpdt */
    bool fil_dpdt_use;
    double fil_dpdt_val;
    bool flag_dpdt;

    /* default recip engine */
    int sample;
    int s_rate;
    int kanal_enable;
    int source_kanal_1;
    int source_kanal_2;
    int trigger_fasa;
    /* pilihan sudut 2-tak */
    double sudut_a_2;
    double sudut_b_2;
    double sudut_c_2;
    double sudut_d_2;
    double sudut_e_2;
    /* pilihan sudut 4-tak */
    double sudut_a_4;
    double sudut_b_4;
    double sudut_c_4;
    double sudut_d_4;
    double sudut_e_4;
    /* nilai sudut */
    int rata_rata;
    /* f_cut-off */
    float fc;
    int terfilter;

    /* default recip compressor */
    int sample_comp;
    int s_rate_comp;
    int kanal_enable_comp;
    int source_kanal_1_comp;
    int source_kanal_2_comp;
    int trigger_fasa_comp;

    /* setting skala recip */
    bool skala_recip;
    double max_amp_recip;
    double min_amp_recip;
    bool skala_pressure;
    double max_pres_val;
    double min_pres_val;

    /* set size untuk print pdf */
    bool print_size;
    bool print_conf;

    /* network database */
    char net_hostname[1024];
    char net_db_name[1024];
    char net_user[256];
    char net_passwd[256];
    //char db_file_name[64];
    int  sql_driver;    // 1 SQLITE, 2 MYSQL, 3 POSTGRE
    QString ip_server;
    int port_server;
    int data_push_server;   // 1 gk dipake, 2 dipake


    /* kirim route */
    QString last_name_data_kirim;
    int last_row_data_kirim;
    int last_column_data_kirim;

    /* untuk flag off route global, keperluan copy data */
    bool copy_off_route;

    /* flag data doesn't exist */
    int dat_avb;

    /* flag copy data form_spektrum */
    bool flag_copy;
    bool flag_copy_pv;

    /* 27 Okt 2014 */
    unsigned short index_rotat;

    unsigned short fft_point_vel;
    unsigned short low_cut_vel;
    unsigned short high_pass_vel;
    unsigned short averages_vel;
    unsigned short window_vel;
    unsigned short PP_vel;

    unsigned short fft_point_acc;
    unsigned short low_cut_acc;
    unsigned short high_pass_acc;
    unsigned short averages_acc;
    unsigned short window_acc;
    unsigned short PP_acc;

    unsigned short fft_point_disp;
    unsigned short low_cut_disp;
    unsigned short high_pass_disp;
    unsigned short averages_disp;
    unsigned short window_disp;
    unsigned short PP_disp;

    unsigned short fft_point_vol;
    unsigned short low_cut_vol;
    unsigned short high_pass_vol;
    unsigned short averages_vol;
    unsigned short window_vol;
    unsigned short PP_vol;

    /* Setting Bahasa */
    int bahasa;

    /* setting show timestamp collect data*/
    int show_timestmap_collect_data=0;

    /*21 Jan 2022 tambah info VID serial USB*/
    int vid=0;

    /*jono default untuk rotating mei 2023*/
        int minAmpWaveRot;
        int maxAmpWaveRot;
        int minTimeWaveRot;
        int maxTimeWaveRot;
        int minAmpSpecRot;
        int maxAmpSpecRot;
        int minHzSpecRot;
        int maxHzSpecRot;
};


#define ID_DATA_RECIP			0xF45AB712 // sebagai indikator nanti saat buka file
struct t_info_recip_xx {
        unsigned int    tak_tak;   // 2 || 4 stroke (karakter '2' atau '4')
        unsigned int    ex_buka;
        unsigned int    ex_tutup;
        unsigned int    in_buka;
        unsigned int    in_tutup;
        float           dia_piston;
        float           l_langkah;
        float           l_rod;

        /* 25 Mar 2010 */
        int anal_gain;			// setting analog gain pada LTC1564
        float MCA;
        int   MPU_palsu;		// jika 0, maka pakai pickup, jika 1, maka palsu
        float dia_rod;
        float dia_rod_head;		// jika tandem

        /* param dsp */
        char enable;			// pressure filter
        char mirror;
        char skala;
        unsigned int stop_P;			/* low cut off */
        unsigned int stop_V;			/* vibrasinya */
        unsigned int start_P;
        unsigned int start_V;

        /* 28 Juli 2010 */
        char dsp;						/* DSP Vibrasi */
        char satuan;					/* G, atau Volt */
        char sample;					/* jumlah sample disimpan, 10, 20, 30, 40 atau 50 */
        int  s_rate;
        int  p_filter;					/* filter pressure, 0 (disable, 1000, 2000, 3000, 4000, 5000) */

        /* 30 Juli 2010 */
        unsigned long 	tim;	 /* waktu saat data disimpan */
        char flag_valid;

        /* 19 Nov 2013 */
        char kanal_enable;       /* 1, 2, atau 3 (dua kanal) */
        char source_kanal_1;     /* 1: Accel, 2: P dinamik, 3 : P Statik */
        char source_kanal_2;     /* 1: Accel, 2: P dinamik */
        char trigger_fase;       /* 1: input, 2: dummy */
        float reff_rpm;

        /* 4 Mei 2014 */
        char satuan_P;          /* 0/1 : bar, 2 = psi, 3 = volt */
        char tipe_sensor_PS;     /* 0/1 : static 5000 psi (default), 2 static 2000 psi, 3 static 1000 psi*/
        char tipe_sensor_PD;     /* 0/1 : dinamik 5000 psi (default), 2 dinamik 2500 psi*/
        char tipe_sensor_ACC;    /* 0/1 : +/- 50 G (default), 2=100 G, 3 = 500 G */

        char show_kurva_PU;     /* kurva pickup dimunculkan */
} ;

struct t_info_recip2{
    unsigned int    tak_tak;   // 2 / 4 stroke (karakter '2' atau '4')
    unsigned int    ex_buka;
    unsigned int    ex_tutup;
    unsigned int    in_buka;
    unsigned int    in_tutup;

    char sample;					/* jumlah sample disimpan, 10, 20, 30, 40 atau 50 */
    int  s_rate;

    char kanal_enable;       /* 1, 2, atau 3 (dua kanal) */
    char source_kanal_1;     /* 1: Accel, 2 : P dinamik, 3 : P Statik */
    char source_kanal_2;     /* 1: Accel, 2: P dinamik */
    char trigger_fase;       /* 1: input, 2 : dummy */
    float reff_rpm;

    char flag_valid;

    /* 25 Mar 2010 */
    int anal_gain;			// setting analog gain pada LTC1564
    float MCA;
    int   MPU_palsu;		// jika 0, maka pakai pickup, jika 1, maka palsu
    float dia_rod;
    float dia_rod_head;		// jika tandem

    /* param dsp */
    char enable;			// pressure filter
    char mirror;
    char skala;
    unsigned int stop_P;			/* low cut off */
    unsigned int stop_V;			/* vibrasinya */
    unsigned int start_P;
    unsigned int start_V;


    /* 28 Juli 2010 */
    char dsp;						/* DSP Vibrasi */
    char satuan_vib;				/* G, atau Volt */
    int  p_filter;					/* filter pressure, 0 (disable, 1000, 2000, 3000, 4000, 5000) */

    /* 30 Juli 2010 */
    unsigned long long	tim;	/* waktu saat data disimpan */
//    char flag_valid;

    /* 4 Mei 2014 */
    char satuan_P;          /* 0/1 : bar, 2 = psi, 3 = volt */
    char tipe_sensor_PS;     /* 0/1 : static 5000 psi (default), 2 static 2000 psi, 3 static 1000 psi*/
    char tipe_sensor_PD;     /* 0/1 : dinamik 5000 psi (default), 2 dinamik 2500 psi*/
    char tipe_sensor_ACC;    /* 0/1 : +/- 50 G (default), 2=100 G, 3 = 500 G */

    char show_kurva_PU;     /* kurva pickup dimunculkan */

};

struct t_info_recip {
        unsigned int    tak_tak;   // 2 / 4 stroke (karakter '2' atau '4')
        unsigned int    ex_buka;
        unsigned int    ex_tutup;
        unsigned int    in_buka;
        unsigned int    in_tutup;
        float           dia_piston;
        float           l_langkah;
        float           l_rod;

        /* 25 Mar 2010 */
        int anal_gain;			// setting analog gain pada LTC1564
        float MCA;
        int   MPU_palsu;		// jika 0, maka pakai pickup, jika 1, maka palsu
        float dia_rod;
        float dia_rod_head;		// jika tandem

        /* param dsp */
        char enable;			// pressure filter
        char mirror;
        char skala;
        unsigned int stop_P;			/* low cut off */
        unsigned int stop_V;			/* vibrasinya */
        unsigned int start_P;
        unsigned int start_V;

        /* 28 Juli 2010 */
        char dsp;						/* DSP Vibrasi */
        char satuan_vib;				/* G, atau Volt */
        char sample;					/* jumlah sample disimpan, 10, 20, 30, 40 atau 50 */
        int  s_rate;
        int  p_filter;					/* filter pressure, 0 (disable, 1000, 2000, 3000, 4000, 5000) */

        /* 30 Juli 2010 */
        unsigned long long	tim;	/* waktu saat data disimpan */
//        unsigned long long	tim;
        char flag_valid;

        /* 19 Nov 2013 */
        char kanal_enable;       /* 1, 2, atau 3 (dua kanal) */
//        unsigned int kanal_enable;       /* 1, 2, atau 3 (dua kanal) */
        char source_kanal_1;     /* 1: Accel, 2 : P dinamik, 3 : P Statik */
        char source_kanal_2;     /* 1: Accel, 2: P dinamik */
        char trigger_fase;       /* 1: input, 2 : dummy */
        float reff_rpm;

        /* 4 Mei 2014 */
        char satuan_P;          /* 0/1 : bar, 2 = psi, 3 = volt */
        char tipe_sensor_PS;     /* 0/1 : static 5000 psi (default), 2 static 2000 psi, 3 static 1000 psi*/
        char tipe_sensor_PD;     /* 0/1 : dinamik 5000 psi (default), 2 dinamik 2500 psi*/
        char tipe_sensor_ACC;    /* 0/1 : +/- 50 G (default), 2=100 G, 3 = 500 G */

        char show_kurva_PU;     /* kurva pickup dimunculkan */
} ;


struct t_info_process{
        float data[10];
        float alarm[4];
        char nama_param[64];          /* tadinya note, diganti nama_param */
};


struct t_dd_recip {
#if 0
    double 	tipe;
    double	id_data;
    double	nomer;		// nomer siklus
    double 	pjg;		// pjg data dalam byte
    double 	jum_sample;	// jum data dalam float, misal jum = 100 berarti 400 byte
#else
    unsigned int 	tipe;
    unsigned int	id_data;
    unsigned int	nomer;		// nomer siklus
    unsigned int 	pjg;		// pjg data dalam byte
    unsigned int 	jum_sample;	// jum data dalam float, misal jum = 100 berarti 400 byte
#endif
    char            dsp;
    char            flag;		// RPM valid, atau sedang menampilkan data
    float  			rpm;
    float 			rms;		// dipakai sebagai real_zero kompresor
    float           maks;
    float           min;
    //unsigned long 	ptr;    // pointer awal pada file
    unsigned int 	ptr;        /* hati2 dengan long & int, pada sistem 64 bit (x86) long dianggap 64 bit,
                                   sementara pada ARM & 32 bit, dianggap 32 bit */
};

/*info aux untuk data rotat maret 2018*/
struct t_dd_rotat {
    float freq1, freq2;
    float amp1, amp2;
    float beda_fase; //beda fasa dual kanal
    bool lead_or_lag;
    float vpp1, vpp2;
    float vrms1, vrms2;
    int tipe;           //
    unsigned int id_data;
    float fasa1; //beda fasa ch1 dengan PU
    float fasa2; //beda fasa ch2 dengan PU
    bool lead_or_lag1; //leading/lagging ch1
    bool lead_or_lag2; //leading/lagging ch2
    //ditambhakan dan disesuaikan ke haliza
    unsigned long long timestamp; //diganti masukkan ke kolom sendiri aja

};

struct t_kalkulasi {
    double       IHP;

    double       sudut_a;
    double       sudut_b;
    double       sudut_c;
    double       sudut_d;
    double       sudut_e;

    double       bb_in;
    double       fire;
    double       peak;
    double       delay;

    double       peak_min;
    double       peak_rata;
    double       peak_maks;
    double       dev;

    double       laju_p;
    double       t_exhaust;
};

struct t_kalkulasi_comp{
    double ihp;
    int stage;

    double ps;
    double pd;
    double rasio;

    double cap_suct;
    double cap_disc;

    double mmscfd_suct;
    double mmscfd_disc;

    double flow_balance;

    double ts;
    double td;
    double beda;

    double ves;
    double ved;

    double rod_load;
    double rod_load_ds;     // Debug 79, data rod load referensi

    int flag_rod_load;      // Debug 74, untuk flag mengubah nilai satuan N menjadi persen di form laporan compressor
};

#define NUM_PASTE   5       /* maksimum ada 5 grafik yang dipaste disini */

struct t_grafik {
    double *data_x;
    double *data_y;
    double *data_y_mirror;      /* untuk vibrasi terfilter */
    int    len;                 /* panjang yang dialokasikan dan yang diperlukan */
    char   nama[64];
    int    flag_valid;          /* jika 1 berarti ada data, jika 0 berarti tidak ada data */
    int    flag_paste;
    int    rand_id;             /* random gen untuk memastikan tidak di paste di tempat yang sama */
    int    tipe_data;
    int    mode_filter;

    double *data_dpdt_x;
    double *data_dpdt_y;
    int flag_valid_dpdt;

    double *data_dpdt2_x;
    double *data_dpdt2_y;
    int flag_valid_dpdt2;

    int mode_dpdt;
    int flag_grafik_copy;
};

struct t_peaks{
    double maks;
    double min;
    int titik_maks;
    int titik_min;
};

struct t_trf_data{
    int len_data;
    double pengali;

    int freq_min;
    int freq_max;

    double amp_min;
    double amp_max;

    int num_harmonics;
    int num_sideband;

    double new_set_rpm;    //dalam satuan Hz
    int fft_point;

    int modified;

};

struct t_setting_rot
{
    QString note;

    int rpm_1;
    int rpm_2;
    double amp_1;
    double amp_2;

    int num_harmonik;
    int num_sideband;

    int new_set_rpm;
};

struct t_add_data
{
    int id;
    int id_aset;
    int id_param;
    int id_tipe_param;
    int id_date;
    int kind;

    int id_siklus[128];
    int index_siklus;
    int num_siklus;
    char db_con_name[128];

    int num_row;
    QString note;
};

struct t_kalkulasi_siklus
{
    int jum_siklus;
//    QVector<double> HP_suc;
//    QVector<double> HP_com;
//    QVector<double> HP_pow;
//    QVector<double> HP_exh;
//    QVector<double> IHP;
//    QVector<double> BB_in;
//    QVector<double> BB_nyala;
//    QVector<double> delay;
//    QVector<double> puncak;
//    QVector<double> p_max;
//    QVector<double> p_min;

//    QVector<double> sudutA;
//    QVector<double> sudutB;
//    QVector<double> sudutC;
//    QVector<double> sudutD;
//    QVector<double> sudutE;

    double HP_suc[24];
    double HP_com[24];
    double HP_pow[24];
    double HP_exh[24];
    double IHP[24];
    double BB_in[24];
    double BB_nyala[24];
    double delay[24];
    double puncak[24];
    double p_max[24];
    double p_min[24];

    double sudutA[24];
    double sudutB[24];
    double sudutC[24];
    double sudutD[24];
    double sudutE[24];
};

struct t_kalkulasi_linked
{
    int jum_siklus;

    double HP_suc;
    double HP_com;
    double HP_pow;
    double HP_exh;
    double IHP;
    double BB_in;
    double BB_nyala;
    double delay;
    double puncak;
    double p_max;
    double p_min;

    double sudutA;
    double sudutB;
    double sudutC;
    double sudutD;
    double sudutE;

    ///struct t_kalkulasi_linked *next;
};

struct t_kalkulasi_comp_linked
{
    double ihp;
    int stage;

    double ps;
    double pd;
    double rasio;

    double cap_suct;
    double cap_disc;

    double mmscfd_suct;
    double mmscfd_disc;

    double flow_balance;

    double ts;
    double td;
    double beda;

    double ves;
    double ved;

    double rod_load;
    double rod_load_ds;     // Debug 79, data rod load referensi

    int flag_rod_load;      // Debug 74, untuk mengubah satuan N menjadi persen di form laporan compresor
};

struct t_kalkulasi_rot
{
    double peak;
    double peak_2_peak;
    double overall;
    double rms;
    double crest_factor;
    double subharmonic;
    double ts_1;
    double ts_2;
    double ts_3_8;
    double ts_9_25;
    double ts_25_70;

};
