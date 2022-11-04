# get .o obj files: (#files[, packet])
# 确定obj的绝对路径： $(OBJDIR)/$(2)/$(1).o
toobj = $(addprefix $(OBJDIR)$(SLASH)$(if $(2),$(2)$(SLASH)),\
		$(addsuffix .o,$(basename $(1))))

# get .d dependency files: (#files[, packet])
# 结果为： $(OBJDIR)/$(2)/$(1).d
todep = $(patsubst %.o,%.d,$(call toobj,$(1),$(2)))

# cc compile template, generate rule for dep, obj: (file, cc[, flags, dir])
# $4：dir 目录
# $3：flags 编译选项
# $2：cc 编译命令
# $1：file 依赖文件
define cc_template
$$(call todep,$(1),$(4)): $(1) | $$$$(dir $$$$@)
	@$(2) -I$$(dir $(1)) $(3) -MM $$< -MT "$$(patsubst %.d,%.o,$$@) $$@"> $$@
$$(call toobj,$(1),$(4)): $(1) | $$$$(dir $$$$@)
	@echo + cc $$<
	$(V)$(2) -I$$(dir $(1)) $(3) -c $$< -o $$@
ALLOBJS += $$(call toobj,$(1),$(4))
endef


# compile file: (#files, cc[, flags, dir])
define do_cc_compile
$(echo $(1))
$$(foreach f,$(1),$$(eval $$(call cc_template,$$(f),$(2),$(3),$(4))))
endef

# compile file: (#files, cc[, flags, dir])
# cc_compile = $(eval $(call do_cc_compile,$(1),$(2),$(3),$(4)))
name := main test

files := $(foreach n,$(names),$(n).o)
main:
	${cc_compile $(name)}
	cc -o main test.cc