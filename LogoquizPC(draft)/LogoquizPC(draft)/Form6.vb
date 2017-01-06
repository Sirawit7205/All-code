Public Class Form6

    Private Sub Button3_Click(sender As System.Object, e As System.EventArgs) Handles Button3.Click
        Close()
    End Sub

    Private Sub Form6_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        TextBox4.Text = My.Settings.hint
        If My.Settings.HintUse(Form2.LevelIdent + Form4.quiz) = 1 Then
            TextBox1.Text = My.Settings.hint_store1(Form2.LevelIdent + Form4.quiz)
            TextBox2.Text = ""
            TextBox3.Text = ""
        ElseIf My.Settings.HintUse(Form2.LevelIdent + Form4.quiz) = 2 Then
            TextBox1.Text = My.Settings.hint_store1(Form2.LevelIdent + Form4.quiz)
            TextBox2.Text = My.Settings.hint_store2(Form2.LevelIdent + Form4.quiz)
            TextBox3.Text = ""
        ElseIf My.Settings.HintUse(Form2.LevelIdent + Form4.quiz) = 3 Then
            TextBox1.Text = My.Settings.hint_store1(Form2.LevelIdent + Form4.quiz)
            TextBox2.Text = My.Settings.hint_store2(Form2.LevelIdent + Form4.quiz)
            TextBox3.Text = My.Settings.hint_store3(Form2.LevelIdent + Form4.quiz)
            Button2.Enabled = False
        Else
            TextBox1.Text = ""
            TextBox2.Text = ""
            TextBox3.Text = ""
        End If
    End Sub

    Private Sub Button2_Click(sender As System.Object, e As System.EventArgs) Handles Button2.Click
        My.Settings.hint -= 1
        TextBox4.Text = My.Settings.hint
        If My.Settings.HintUse(Form2.LevelIdent + Form4.quiz) = 0 Then
            TextBox1.Text = My.Settings.hint_store1(Form2.LevelIdent + Form4.quiz)
            My.Settings.HintUse(Form2.LevelIdent + Form4.quiz) = 1
        ElseIf My.Settings.HintUse(Form2.LevelIdent + Form4.quiz) = 1 Then
            TextBox2.Text = My.Settings.hint_store2(Form2.LevelIdent + Form4.quiz)
            My.Settings.HintUse(Form2.LevelIdent + Form4.quiz) = 2
        ElseIf My.Settings.HintUse(Form2.LevelIdent + Form4.quiz) = 2 Then
            TextBox3.Text = My.Settings.hint_store3(Form2.LevelIdent + Form4.quiz)
            My.Settings.HintUse(Form2.LevelIdent + Form4.quiz) = 3
            Button2.Enabled = False
        End If
    End Sub

    Private Sub Button1_Click(sender As System.Object, e As System.EventArgs) Handles Button1.Click
        Me.Close()
        Form7.Show()
    End Sub
End Class